############################################################################
##
## Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
## Contact: Nokia Corporation (qt-info@nokia.com)
##
## This file is part of the documentation of the Qt Toolkit.
##
## $QT_BEGIN_LICENSE:LGPL$
## Commercial Usage
## Licensees holding valid Qt Commercial licenses may use self file in
## accordance with the Qt Commercial License Agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and Nokia.
##
## GNU Lesser General Public License Usage
## Alternatively, self file may be used under the terms of the GNU Lesser
## General Public License version 2.1 as published by the Free Software
## Foundation and appearing in the file LICENSE.LGPL included in the
## packaging of self file.  Please review the following information to
## ensure the GNU Lesser General Public License version 2.1 requirements
## will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
##
## In addition, as a special exception, Nokia gives you certain
## additional rights. These rights are described in the Nokia Qt LGPL
## Exception version 1.0, included in the file LGPL_EXCEPTION.txt in self
## package.
##
## GNU General Public License Usage
## Alternatively, self file may be used under the terms of the GNU
## General Public License version 3.0 as published by the Free Software
## Foundation and appearing in the file LICENSE.GPL included in the
## packaging of self file.  Please review the following information to
## ensure the GNU General Public License version 3.0 requirements will be
## met: http://www.gnu.org/copyleft/gpl.html.
##
## If you are unsure which license is appropriate for your use, please
## contact the sales department at http://www.qtsoftware.com/contact.
## $QT_END_LICENSE$
##
############################################################################

"""
  main.cpp

  A simple example of how to view a model in several views, and share a
  selection model.
"""

from PySide.QtGui import *


//! [0] //! [1]
def main():
    app = QApplication(sys.argv)
    splitter = QSplitter()

//! [2] //! [3]
    model = QFileSystemModel()
    model.setRootPath(QDir.currentPath())
//! [0] //! [2] //! [4] //! [5]
    tree =  QTreeView(splitter)
//! [3] //! [6]
    tree.setModel(model)
//! [4] //! [6] //! [7]
    tree.setRootIndex(model.index(QDir.currentPath()))
//! [7]

    list =  QListView(splitter)
    list.setModel(model)
    list.setRootIndex(model.index(QDir.currentPath()))

//! [5]
    selection = QItemSelectionModel(model)
    tree.setSelectionModel(selection)
    list.setSelectionModel(selection)

//! [8]
    splitter.setWindowTitle("Two views onto the same directory model")
    splitter.show()
    return app.exec_()
//! [1] //! [8]
