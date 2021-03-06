/***************************************************************************
                         qgsbrightnesscontrastfilter.h
                         -------------------
    begin                : February 2013
    copyright            : (C) 2013 by Alexander Bruy
    email                : alexander dot bruy at gmail dot com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef QGSBRIGHTNESSCONTRASTFILTER_H
#define QGSBRIGHTNESSCONTRASTFILTER_H

#include "qgsrasterdataprovider.h"
#include "qgsrasterinterface.h"

class QDomElement;

/** \ingroup core
  * Brightness/contrast filter pipe for rasters.
  */
class CORE_EXPORT QgsBrightnessContrastFilter : public QgsRasterInterface
{
  public:
    QgsBrightnessContrastFilter( QgsRasterInterface *input = 0 );
    ~QgsBrightnessContrastFilter();

    QgsRasterInterface * clone() const;

    int bandCount() const;

    QGis::DataType dataType( int bandNo ) const;

    bool setInput( QgsRasterInterface* input );

    QgsRasterBlock *block( int bandNo, const QgsRectangle &extent, int width, int height );

    void setBrightness( int brightness ) { mBrightness = qBound( -255, brightness, 255 ); }
    int brightness() const { return mBrightness; }

    void setContrast( int contrast ) { mContrast = qBound( -100, contrast, 100 ); }
    int contrast() const { return mContrast; }

    void writeXML( QDomDocument& doc, QDomElement& parentElem );

    /**Sets base class members from xml. Usually called from create() methods of subclasses*/
    void readXML( const QDomElement& filterElem );

  private:
    /** Current brightness coefficient value. Default: 0. Range: -255...255 */
    int mBrightness;

    /** Current contrast coefficient value. Default: 0. Range: -100...100 */
    double mContrast;
};

#endif // QGSBRIGHTNESSCONTRASTFILTER_H
