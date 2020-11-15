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
        insDoc(sub1, gLnk("R", "The main window", "./main_window.html"))
    sub1 = insFld(foldersTree, gFld("Selecting a window", "javascript:parent.op()"))
        insDoc(sub1, gLnk("R", "Picking a window using the mouse", "./pick_window.html"))
        insDoc(sub1, gLnk("R", "Using the hierarchy tree", "./window_tree.html"))
        insDoc(sub1, gLnk("R", "Searching for a window", "./search.html"))
    sub1 = insFld(foldersTree, gFld("Window Properties", "javascript:parent.op()"))
        insDoc(sub1, gLnk("R", "Viewing Properties", "./viewing_properties.html"))
        insDoc(sub1, gLnk("R", "Setting Properties", "./setting_properties.html"))
        insDoc(sub1, gLnk("R", "Window Styles", "./setting_styles.html"))
    sub1 = insFld(foldersTree, gFld("Window Messages", "javascript:parent.op()"))
        insDoc(sub1, gLnk("R", "Montioring a window's messages", "./window_messages.html"))
    sub1 = insFld(foldersTree, gFld("Settings", "javascript:parent.op()"))
        sub2 = insFld(sub1, gFld("Preferences", "./preferences_overview.html"))
            insDoc(sub2, gLnk("R", "General", "./preferences_general.html"))
            insDoc(sub2, gLnk("R", "Window Tree", "./preferences_window_tree.html"))
            insDoc(sub2, gLnk("R", "Picker", "./preferences_picker.html"))
            insDoc(sub2, gLnk("R", "Logging", "./preferences_logging.html"))
            insDoc(sub2, gLnk("R", "Styles", "./preferences_styles.html"))
      insDoc(sub1, gLnk("R", "Smart Settings", "./smart_settings.html"))