//
// Copyright (c) 2006 by Conor O'Mahony.
// For enquiries, please email GubuSoft@GubuSoft.com.
// Please keep all copyright notices below.
// Original author of TreeView script is Marcelino Martins.
//
// This document includes the TreeView script.
// The TreeView script can be found at http://www.TreeView.net.
// The script is Copyright (c) 2006 by Conor O'Mahony.
//
// You can find general instructions for this file at www.treeview.net. 
//

// Configures whether the names of the nodes are links (or whether only the icons
// are links).
USETEXTLINKS = 1

// Configures whether the tree is fully open upon loading of the page, or whether
// only the root node is visible.
STARTALLOPEN = 0

// Specify if the images are in a subdirectory;
ICONPATH = 'images/treeview/'


foldersTree = gFld("<i>Window Detective</i>", "./intro.html")
foldersTree.treeID = "Frameset"
sub1 = insFld(foldersTree, gFld("Introduction", "./intro.html"))
    insDoc(sub1, gLnk("R", "Features", "./features.html"))
    insDoc(sub1, gLnk("R", "The Main Interface", "./main_window.html"))
    insDoc(sub1, gLnk("R", "Translating", "./translating.html"))
sub1 = insFld(foldersTree, gFld("Selecting a Window", "./selecting_window_intro.html"))
    insDoc(sub1, gLnk("R", "Picking a Window Using the Mouse", "./pick_window.html"))
    insDoc(sub1, gLnk("R", "Using the Hierarchy Tree", "./window_tree.html"))
    insDoc(sub1, gLnk("R", "Searching for a Window", "./search.html"))
sub1 = insFld(foldersTree, gFld("Window Properties", "window_properties_intro.html"))
    insDoc(sub1, gLnk("R", "Viewing Properties", "./viewing_properties.html"))
    insDoc(sub1, gLnk("R", "Setting Properties", "./setting_properties.html"))
    insDoc(sub1, gLnk("R", "Setting Window Styles", "./setting_styles.html"))
sub1 = insFld(foldersTree, gFld("Window Messages", "window_messages_intro.html"))
    insDoc(sub1, gLnk("R", "Montioring a Window's Messages", "./window_messages.html"))
sub1 = insFld(foldersTree, gFld("System Info", "system_info_intro.html"))
    insDoc(sub1, gLnk("R", "Viewing System UI Settings", "./system_info.html"))
sub1 = insFld(foldersTree, gFld("Settings", "settings_intro.html"))
    sub2 = insFld(sub1, gFld("Preferences", "./preferences_intro.html"))
        insDoc(sub2, gLnk("R", "General", "./preferences_general.html"))
        insDoc(sub2, gLnk("R", "Window Tree", "./preferences_window_tree.html"))
        insDoc(sub2, gLnk("R", "Picker", "./preferences_picker.html"))
        insDoc(sub2, gLnk("R", "Logging", "./preferences_logging.html"))
        insDoc(sub2, gLnk("R", "Styles", "./preferences_styles.html"))
    sub2 = insFld(sub1, gFld("Custom Window Data", "./user_data.html"))
        insDoc(sub2, gLnk("R", "Defining Custom Messages", "./custom_messages.html"))
        insDoc(sub2, gLnk("R", "Window Class Icons", "./window_class_icons.html"))
    insDoc(sub1, gLnk("R", "Smart Settings", "./smart_settings.html"))