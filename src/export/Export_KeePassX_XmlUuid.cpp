/***************************************************************************
 *   Copyright (C) 2007 by Tarek Saidi                                     *
 *   tarek.saidi@arcor.de                                                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *

 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "Export_KeePassX_Xml_Uuid.h"

bool Export_KeePassX_XmlUuid::exportDatabase(QWidget* GuiParent,IDatabase* database) {
	db=database;
	// determine output file
	QFile *file=openFile(GuiParent,identifier(),QStringList()<<tr("XML Files (*.xml)") << tr("All Files (*)"));
	if(!file) {
		return false;
	}
	QDomDocument doc("KEEPASSX_DATABASE_BYUUID");
	QDomElement root=doc.createElement("database");
	doc.appendChild(root);
	QList<IEntryHandle*> entries = database->entriesSortedUuid();
	for(int i=0;i<entries.size();i++){
		addEntry(entries[i],root,doc);
		}

	file->write(doc.toByteArray());
	file->close();
	delete file;
	return true;
}
