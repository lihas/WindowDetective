///////////////////////////////////////////////////////////////////////////
////////                                                                 //
//    _       _   _             __                                       //
//   | |     / / (_) ____  ____/ /____  _      __                        //
//   | | /| / / / / / __ \/ __  // __ \| | /| / /                        //
//   | |/ |/ / / / / / / / /_/ // /_/ /| |/ |/ /                         //
//   |__/|__/ /_/ /_/ /_/\__,_/ \____/ |__/|__/                          //
//             ____         __              __    _                      //
//            / __ \ ___ __/ /_ ___  ______/ /_  (_)_   __ ___           //
//           / / / // _ \_  __// _ \/ ___/  __/ / /| | / // _ \          //
//          / /_/ //  __// /_ /  __/ /__ / /_  / / | |/ //  __/          //
//         /_____/ \___/ \__/ \___/\___/ \__/ /_/  |___/ \___/           //
//                                                                       //
//   Version 3.5.1         http://windowdetective.sourceforge.net/       //
//                                                                 ////////
///////////////////////////////////////////////////////////////////////////


Window Detective is a programmer's tool used to "spy" on an application's
windows and allows you to view and even modify some of it's properties.


Key Features
------------
* View properties of windows such as text/title, dimensions and styles.
* Set properties such as text/title, dimensions and styles.
* View all windows in a tree hierarchy of parent/child windows.
* 'Pick' windows to inspect using the mouse.
* Advanced search which allows you to find windows that match specified
  criteria.
* Listen for window messages sent to a window.
* "Smart Settings" that intelligently remember user settings such as
  window positions.


Changes In This Release
-----------------------
Bugs fixed
 - ID #10. Crash when capturing messages.


Known Issues
------------
* Hook DLL is 32-bit and therefore will not work with 64-bit processes.
* When a lot of windows are destroyed, some of them may not be removed from
  the window tree. Refreshing the tree will fix this.
* Getting extra window info (i.e. font, background brush) will fail for
  certain windows. I have noticed this for some of Firefox's windows.


Feedback
--------
If you've got any question or suggestion or have any bugs to report, you can
create a ticket at https://sourceforge.net/p/windowdetective/_list/tickets,
or e-mail me at <xtal256@hotmail.com>.


Source Code
-----------
The source code for each version of Window Detective can be downloaded
from SourceForge at the same place as the installers.

It is packaged as a zip file which contains the source code as well as the
binaries and data required to run the program. Installation is not required,
although settings will not be saved unless the "Window Detective" registry
key exists under HKCU\Software\.

To build the source code, you will need Microsoft Visual Studio and the Qt
framework. You can download Qt from https://www.qt.io/download-open-source.
I work with Visual Studio 2010 and Qt 5.1.0, but it should be possible to
build with other versions.
