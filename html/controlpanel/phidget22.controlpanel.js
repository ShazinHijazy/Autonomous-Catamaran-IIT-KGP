/// <reference types="jquery" />
/// <reference types="jqueryui" />
/// <reference types="jstree" />
/// <reference types="phidget22" />
"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
(function () {
    /**************************************************************************************************
     * ControlPanel
     */
    let jstree;
    function isConnection(obj) {
        const usbConn = phidget22.USBConnection;
        const netConn = phidget22.NetworkConnection;
        if (netConn !== undefined && obj instanceof netConn)
            return true;
        if (usbConn !== undefined && obj instanceof usbConn)
            return true;
        return false;
    }
    function isUSBConnection(obj) {
        const usbConn = phidget22.USBConnection;
        if (usbConn !== undefined && obj instanceof usbConn)
            return true;
        return false;
    }
    function isPhidget(obj) {
        if (phidget22.Phidget !== undefined && obj instanceof phidget22.Phidget)
            return true;
        return false;
    }
    class ControlPanel {
        constructor(div) {
            this.ppdata = null;
            this.basediv = div;
            this.userdiv = '#' + div;
            const treediv = this.basediv + '_body';
            this.treediv = '#' + treediv;
            if (!$.jstree)
                throw (new Error("missing jquery jstree"));
            $(this.userdiv).html('<div class="PhidgetControlPanel" id="' + this.basediv + '">' +
                '<div class="PhidgetControlPanelHeader" id="' + this.basediv + '_header">Phidget22 JavaScript Control Panel</div>' +
                '<div class="RequestUSB" id="' + this.basediv + '_usbrequest"><button id="requestAccess">Connect USB Device</button></div>' +
                '<div class="PhidgetControlPanelBody" id="' + this.basediv + '_body"></div>' +
                '<div class="PhidgetControlPanelFooter" id="' + this.basediv + '_footer">Double Click to Launch UI</div>' +
                '<div id="' + this.basediv + '_dialogs"></div>' +
                '<div id="error_dialog"></div>' +
                '</div>');
            const tree = {
                core: {
                    check_callback: true,
                    dblclick_toggle: false
                },
                plugins: ['grid', 'contextmenu', 'sort'],
                contextmenu: {
                    items: (node) => {
                        const menu = {};
                        let chnode;
                        const openItem = {
                            label: 'Open',
                            action: () => {
                                this.openChannel(chnode);
                            }
                        };
                        if (node.id.startsWith('dev_')) {
                            const devNode = node;
                            if (devNode.data && devNode.data.obj) {
                                if (devNode.data.obj.getDeviceClass() !== phidget22.DeviceClass.VINT) {
                                    menu.setlabel = {
                                        label: 'Set Label...',
                                        action: () => {
                                            this.writeLabel(devNode);
                                        }
                                    };
                                }
                            }
                            if (devNode.data.channel === 0) {
                                chnode = jstree.get_node(devNode.children[0]);
                                if (chnode.data && chnode.data.obj)
                                    menu.open = openItem;
                            }
                        }
                        if (node.id.startsWith('ch_')) {
                            chnode = node;
                            if (chnode.data && chnode.data.obj)
                                menu.open = openItem;
                        }
                        if (node.id.startsWith('conn_')) {
                            const conn = node.data.conn;
                            if (conn.connected) {
                                menu.close = {
                                    label: 'Close',
                                    action: () => {
                                        conn.close();
                                    }
                                };
                            }
                            else {
                                menu.connect = {
                                    label: 'Connect',
                                    action: () => {
                                        conn.connect();
                                    }
                                };
                            }
                        }
                        return (menu);
                    }
                },
                sort: function (a, b) {
                    const nodea = jstree.get_node(a);
                    const nodeb = jstree.get_node(b);
                    if (nodea.text !== nodeb.text)
                        return (nodea.text > nodeb.text ? 1 : -1);
                    if (nodea.data.serial != undefined && nodeb.data.serial != undefined && nodea.data.serial !== nodeb.data.serial)
                        return (nodea.data.serial > nodeb.data.serial ? 1 : -1);
                    if (nodea.data.channel != undefined && nodeb.data.channel != undefined && nodea.data.channel !== nodeb.data.channel)
                        return (nodea.data.channel > nodeb.data.channel ? 1 : -1);
                    return (this.get_text(a) > this.get_text(b) ? 1 : -1);
                },
                grid: {
                    columns: [
                        {
                            header: 'name',
                            //width: 99%
                        },
                        {
                            header: 'SKU',
                            value: 'sku',
                            width: 120
                        },
                        {
                            header: 'Serial #',
                            value: 'serial',
                            cellClass: 'cell-right-align',
                            width: 75
                        },
                        {
                            header: 'Label',
                            value: 'label',
                            width: 120
                        },
                        {
                            header: 'Channel',
                            value: 'channel',
                            cellClass: 'cell-right-align',
                            width: 60
                        },
                        {
                            header: 'Version',
                            value: 'version',
                            cellClass: 'cell-right-align',
                            width: 60
                        }
                    ],
                    //resizable: true,
                    //height: 600
                }
            };
            $(this.treediv).jstree(tree);
            jstree = $(this.treediv).jstree(true);
            $(this.treediv).on('dblclick', (e) => {
                const $node = $(e.target).closest('li');
                const id = $node.attr('id');
                if (!id)
                    return;
                const node = jstree.get_node(id);
                if (id.startsWith('ch_')) {
                    this.openChannel(node);
                    return;
                }
                if (node.id.startsWith('dev_')) {
                    const devNode = node;
                    if (devNode.data.channel === 0) {
                        const chnode = jstree.get_node(devNode.children[0]);
                        if (chnode.data && chnode.data.obj) {
                            this.openChannel(chnode);
                            return;
                        }
                    }
                }
                jstree.toggle_node(node);
            });
            /*
            * Create a manager to find out about channels.
            */
            const manager = new phidget22.Manager({
                onDeviceAttach: this.add.bind(this),
                onDeviceDetach: this.remove.bind(this),
                onAttach: this.add.bind(this),
                onDetach: this.remove.bind(this)
            });
            manager.open();
            /* Future connections */
            phidget22.Connection.setOnConnectionAdded(this.add.bind(this));
            phidget22.Connection.setOnConnectionRemoved(this.remove.bind(this));
        }
        showOrHideVintPortDevices(port) {
            let vintDeviceAttached = false;
            for (const c of port.children) {
                const dev = jstree.get_node(c);
                if (!dev.data.obj.getIsHubPortDevice()) {
                    vintDeviceAttached = true;
                    break;
                }
            }
            if (vintDeviceAttached)
                jstree.open_node(port);
            else
                jstree.close_node(port);
            for (const c of port.children) {
                const dev = jstree.get_node(c);
                if (dev.data.obj.getIsHubPortDevice()) {
                    if (vintDeviceAttached && !jstree.is_hidden(dev))
                        jstree.hide_node(dev, false);
                    else if (!vintDeviceAttached && jstree.is_hidden(dev))
                        jstree.show_node(dev, false);
                }
            }
        }
        /* centralize div id creation */
        mkDiv(obj, isVintPort = false) {
            if (isPhidget(obj) && isVintPort)
                return ('vint_port_' + obj.getHub().getKey() + '_' + obj.getHubPort());
            if (isConnection(obj))
                return ('conn_' + this.basediv + '_' + obj.getKey());
            else if (isPhidget(obj)) {
                if (obj.getIsChannel())
                    return ('ch_' + this.basediv + '_' + obj.getKey());
                else
                    return ('dev_' + this.basediv + '_' + obj.getKey());
            }
            throw new Error("Unexpected");
        }
        mkDialogDiv(ch, suffix) {
            return (this.basediv + '_' + ch.getKey() + suffix);
        }
        writeLabel(node) {
            const jstree = $(this.treediv).jstree(true);
            // Find a channel child
            for (const c of node.children) {
                const n = jstree.get_node(c);
                if (isPhidget(n.data.obj) && n.data.obj.getIsChannel()) {
                    this.openChannel(n, true);
                    return;
                }
            }
        }
        openChannel(node, writeLabel = false) {
            const phid = node.data.obj;
            if (phid == undefined)
                throw new Error("Unexpected");
            if (node.data.phidget) {
                // Already opening
                return;
            }
            node.data.phidget = phid;
            phid.onError = function (code, msg) {
                // Handle this error - it probably means the Phidget is open elsewhere
                // NOTE: it's only safe to handle this because we are specifing a specific channel we want to open
                if (code == phidget22.ErrorEventCode.BUSY || code == phidget22.ErrorEventCode.FAILURE) {
                    // close so the library doesn't keep trying to open this channel
                    phid.close();
                    delete node.data.phidget;
                    $("#error_dialog").html("<p>Unable to open Phidget: " + msg + "</p><p>This channel may be open elsewhere, or you may not have access.</p>");
                    $("#error_dialog").dialog({
                        title: "Unable to open",
                        height: 'auto',
                        close: function () {
                            $("#error_dialog").empty();
                        }
                    });
                    return;
                }
                console.error("Error event during open", msg);
            };
            phid.onAttach = () => {
                this.render(phid, writeLabel);
            };
            phid.onDetach = () => {
                if (typeof PhidgetPanel !== 'undefined')
                    PhidgetPanel.toggle(phid, this.mkDialogDiv(phid, ''));
                delete node.data.phidget;
            };
            phid.open(phidget22.Phidget.DEFAULT_TIMEOUT).catch(function (err) {
                // This case is caused by closing the channel from the onError event above.
                if (err.errorCode === phidget22.ErrorCode.CLOSED)
                    return;
                delete node.data.phidget;
                $("#error_dialog").html("<p>Unable to open Phidget: " + err.message + "</p>");
                $("#error_dialog").dialog({
                    title: "Unable to open",
                    height: 'auto',
                    close: function () {
                        $("#error_dialog").empty();
                    }
                });
            });
        }
        render(phid, writeLabel = false) {
            if (this.ppdata === null) {
                /*
                 * Load PhidgetPanel.
                 */
                $.get('/controlpanel/PhidgetPanel.html', (data) => {
                    this.ppdata = data;
                    this.render(phid, writeLabel);
                });
                return;
            }
            // Channel may have detached while loading PhidgetPanel
            if (!phid.getAttached())
                return;
            const key = this.mkDialogDiv(phid, '');
            let ppdiv = $('#' + this.mkDialogDiv(phid, '_phidgetpanel_content'));
            if (ppdiv.length) {
                const example = window[phid.getChannelClassName().substring(7) + 'Example'];
                if (!example)
                    throw (phid.getChannelClassName().substring(7) + ' Example not found');
                example.setup(phid);
                PhidgetPanel.toggle(phid, key);
                return;
            }
            const ddiv = $('#' + this.mkDialogDiv(phid, '_dialog'));
            const data = this.ppdata.replace(/\$KEY/g, this.basediv + '_' + phid.getKey());
            ddiv.hide();
            ddiv.html(data);
            PhidgetPanel.setup(phid, key);
            PhidgetPanel.toggle(phid, key);
            ppdiv = $('#' + this.mkDialogDiv(phid, '_phidgetpanel_content'));
            let exname = phid.getChannelClassName().substring(7);
            if (phid.getChannelClass() === phidget22.ChannelClass.DICTIONARY && phid.getDeviceSerialNumber() == 2)
                exname = 'ControlDictionary';
            if (writeLabel === true)
                exname = 'WriteLabel';
            $.get('/controlpanel/' + exname + '.html', (data) => {
                // Channel may have detached while loading example
                if (!phid.getAttached())
                    return;
                const nodeid = this.mkDiv(phid);
                data = data.replace(/\$KEY/g, key);
                ppdiv.empty();
                ppdiv.html(data);
                const example = window[exname + 'Example'];
                if (!example)
                    throw (exname + ' Example not found');
                example.setup(phid);
                ddiv.dialog({
                    title: writeLabel ? 'Write Label' : phid.getChannelName(),
                    autoOpen: false,
                    modal: false,
                    show: "blind",
                    hide: "blind",
                    width: example.width ? example.width : 'auto',
                    height: 'auto',
                    open: () => { },
                    close: () => {
                        const jstree = $(this.treediv).jstree(true);
                        phid.close();
                        const node = jstree.get_node(nodeid);
                        if (node)
                            delete node.data.phidget;
                        if (writeLabel) {
                            try {
                                const parentnode = jstree.get_node(this.mkDiv(phid.getParent()));
                                parentnode.data.label = phid.getDeviceLabel();
                                jstree.redraw_node(parentnode, false, false, false);
                                // eslint-disable-next-line no-empty
                            }
                            catch (_a) { }
                        }
                        if (example.teardown)
                            example.teardown(phid);
                        ddiv.empty();
                    }
                });
                ddiv.show();
                ddiv.dialog('open');
            });
        }
        add(obj) {
            const jstree = $(this.treediv).jstree(true);
            const nodeid = this.mkDiv(obj);
            let node = jstree.get_node(nodeid);
            /*
             * If there is a user phidget attached, we are waiting for a device that was attached
             * and then went away, but was not closed by the control panel; otherwise, this is
             * a bug.
             */
            if (node !== false)
                return;
            if (isPhidget(obj)) {
                if (obj.getIsChannel()) {
                    const ch = obj;
                    const chnode = {
                        id: this.mkDiv(ch),
                        text: ch.getChannelName(),
                        data: {
                            channel: ch.getChannel(),
                            obj: ch
                        }
                    };
                    const parent = '#' + this.mkDiv(ch.getParent());
                    if (!(node = jstree.create_node(parent, chnode, 'last')))
                        throw (new Error('failed to add new node for channel: ' + ch));
                    jstree.hide_icon(node);
                    const parentnode = jstree.get_node(this.mkDiv(ch.getParent()));
                    if (parentnode.children.length > 1) {
                        for (const c of parentnode.children) {
                            const childnode = jstree.get_node(c);
                            if (jstree.is_hidden(childnode))
                                jstree.show_node(childnode, false);
                        }
                        if (parentnode.data.channel === 0) {
                            delete parentnode.data.channel;
                            jstree.redraw_node(parentnode, false, false, false);
                        }
                    }
                    else {
                        jstree.hide_node(node, false);
                    }
                    // Hide HUB channels
                    if (ch.getChannelClass() === phidget22.ChannelClass.HUB)
                        jstree.hide_node(node, false);
                    /*
                     * Add the dialog div.
                     */
                    const ddiv = this.mkDialogDiv(ch, '_dialog');
                    const cdiv = this.mkDialogDiv(ch, '_dialog_content');
                    if ($('#' + ddiv).length === 0) {
                        const dsdiv = $('#' + this.basediv + '_dialogs');
                        dsdiv.append('<div id="' + ddiv + '"><div id="' + cdiv + '"></div></div>');
                    }
                }
                else {
                    const dev = obj;
                    const devnode = {
                        id: nodeid,
                        text: dev.getDeviceName(),
                        children: [],
                        data: {
                            version: dev.getDeviceVersion(),
                            channel: 0,
                            obj: dev
                        }
                    };
                    if (dev.getDeviceClass() === phidget22.DeviceClass.HUB)
                        devnode.state = { opened: true };
                    if (dev.getDeviceClass() === phidget22.DeviceClass.VINT) {
                        if (dev.VINTDeviceSupportsSetSpeed)
                            devnode.icon = '/controlpanel/style/vinths.png';
                        else
                            devnode.icon = '/controlpanel/style/vint.png';
                        if (!dev.getIsHubPortDevice())
                            devnode.data.sku = dev.getDeviceSKU();
                        let portid = this.mkDiv(dev, true);
                        let port = jstree.get_node(portid);
                        if (!port) {
                            const parent = '#' + this.mkDiv(dev.getParent());
                            const portnode = {
                                id: portid,
                                text: 'Port ' + dev.getHubPort(),
                                icon: '/controlpanel/style/vint.png',
                                children: [],
                                data: {}
                            };
                            if (dev.hubPortSupportsSetSpeed) {
                                portnode.icon = '/controlpanel/style/vinths.png';
                                portnode.text += ' (High Speed)';
                            }
                            portid = jstree.create_node(parent, portnode, 'last');
                            if (!portid)
                                throw (new Error('failed to add new hub port node'));
                            port = portnode;
                        }
                        if (!(node = jstree.create_node(portid, devnode, 'last')))
                            throw (new Error('failed to add new node for vint device: ' + dev));
                        if (dev.getIsHubPortDevice())
                            jstree.hide_icon(node);
                        this.showOrHideVintPortDevices(port);
                    }
                    else {
                        if (dev.getDeviceClass() === phidget22.DeviceClass.DICTIONARY)
                            devnode.icon = '/controlpanel/style/virtual.png';
                        else
                            devnode.icon = '/controlpanel/style/usb.png';
                        devnode.data.serial = dev.getDeviceSerialNumber();
                        devnode.data.label = dev.getDeviceLabel();
                        devnode.data.sku = dev.getDeviceSKU();
                        let parent;
                        if (dev.getParent())
                            parent = '#' + this.mkDiv(dev.getParent());
                        else
                            parent = '#' + this.mkDiv(dev.getConnection());
                        if (!(node = jstree.create_node(parent, devnode, 'last')))
                            throw (new Error('failed to add new node for device: ' + dev));
                    }
                }
            }
            else if (isConnection(obj)) {
                const connnode = {
                    id: this.mkDiv(obj),
                    text: obj.name,
                    icon: isUSBConnection(obj) ? '/controlpanel/style/usb.png' : '/controlpanel/style/net.png',
                    state: { opened: true },
                    children: [],
                    data: {
                        conn: obj
                    }
                };
                jstree.create_node(null, connnode, 'last');
                if (isUSBConnection(obj)) {
                    $('#' + this.basediv + '_usbrequest').show();
                    $('#requestAccess').click(() => __awaiter(this, void 0, void 0, function* () {
                        try {
                            obj.requestWebUSBDeviceAccess();
                        }
                        catch (err) {
                            console.error('Request device error', err);
                        }
                    }));
                }
            }
        }
        remove(obj) {
            if (isPhidget(obj)) {
                const jstree = $(this.treediv).jstree(true);
                const nodeid = this.mkDiv(obj);
                const node = jstree.get_node(nodeid);
                if (node === false) {
                    console.log('unable to find node for:' + obj + ' (' + nodeid + ')');
                    return;
                }
                /*
                 * We do not remove nodes with children just to enforce strict handing of the
                 * tree in the rest of the code.
                 */
                if (!jstree.is_leaf(node)) {
                    console.log('node ' + obj + ' still has children!');
                    return;
                }
                if (node.data.phidget)
                    delete node.data.phidget;
                jstree.delete_node(node);
                /*
                 * Remove the 'Port #' node if it is now empty.
                 */
                if (!obj.getIsChannel() && obj.getDeviceClass() === phidget22.DeviceClass.VINT) {
                    const portid = this.mkDiv(obj, true);
                    const node = jstree.get_node(portid);
                    if (node === false)
                        return;
                    if (jstree.is_leaf(node))
                        jstree.delete_node(node);
                    else
                        this.showOrHideVintPortDevices(node);
                }
            }
            else if (isConnection(obj)) {
                const jstree = $(this.treediv).jstree(true);
                const nodeid = this.mkDiv(obj);
                const node = jstree.get_node(nodeid);
                if (node === false) {
                    console.log('unable to find node for:' + obj + ' (' + nodeid + ')');
                    return;
                }
                jstree.delete_node(node);
                if (isUSBConnection(obj))
                    $('#' + this.basediv + '_usbrequest').hide();
            }
        }
    }
    // We add ControlPanel to the global phidget22 namespace
    phidget22.ControlPanel = ControlPanel;
}());
//# sourceMappingURL=phidget22.controlpanel.js.map