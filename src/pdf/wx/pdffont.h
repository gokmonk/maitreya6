///////////////////////////////////////////////////////////////////////////////
// Name:        pdffont.h
// Purpose:     
// Author:      Ulrich Telle
// Modified by:
// Created:     2008-08-10
// Copyright:   (c) Ulrich Telle
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

/// \file pdffont.h Interface of wxPdfFont class

#ifndef _PDF_FONT_H_
#define _PDF_FONT_H_

// wxWidgets headers
#include <wx/mstream.h>

// wxPdfDocument headers
#include "wx/pdfdocdef.h"
#include "wx/pdffontdescription.h"
#include "wx/pdfproperties.h"

class WXDLLIMPEXP_FWD_PDFDOC wxPdfEncoding;
class WXDLLIMPEXP_FWD_PDFDOC wxPdfFontData;

/// Class representing a font providing a basic interface
class WXDLLIMPEXP_PDFDOC wxPdfFont
{
public :
  /// Default constructor
  wxPdfFont() ;

  /// Default destructor
  virtual ~wxPdfFont() ;

  /// Copy constructor
  wxPdfFont(const wxPdfFont& font);

  /// Assignment
  wxPdfFont& operator=(const wxPdfFont& font);

  /// Check whether font is valid
  /**
  * \return TRUE if the font is valid, FALSE otherwise
  */
  bool IsValid() const;

  /// Get font type
  /**
  * \return the font type
  */
  wxString GetType() const;

  /// Get font family
  /**
  * \return the font family
  */
  wxString GetFamily() const;

  /// Get font name
  /**
  * \return the font name
  */
  wxString GetName() const;

  /// Get font style
  /**
  * \return the font style
  */
  int GetStyle() const;

  /// Get encoding
  /**
  * \return the name of the font encoding
  */
  wxString GetEncoding() const;

  /// Get the width of a string
  /**
  * \param s string which's width is to be returned
  * \return the width of the string
  */
  virtual double GetStringWidth(const wxString& s) const;

  /// Check whether the font embedding is required
  /**
  * \return TRUE if embedding of this font is required, FALSE otherwise
  */
  bool EmbedRequired() const;

  /// Check whether the font embedding is supported
  /**
  * \return TRUE if embedding of this font is supported/allowed, FALSE otherwise
  */
  bool EmbedSupported() const;

  /// Check whether the font subsetting is supported
  /**
  * \return TRUE if subsetting of this font is supported/allowed, FALSE otherwise
  */
  bool SubsetSupported() const;

  /// Get the font description
  /**
  * \return the font description
  */
  const wxPdfFontDescription GetDescription() const;

  /// Set embed flag
  /**
  * Enables or disables embedding for the font. Embedding can be enabled if and only if
  * the font allows embedding. Embedding can be disabled if and only if the font does
  * not requires embedding.
  * \param embed Indicates whether to embed or not embed the font
  * \see EmbedRequired(), EmbedSupported()
  */
  void SetEmbed(bool embed);

  /// Get embed flag
  /**
  * \return TRUE if the font will be embedded, FALSE otherwise
  * \see EmbedRequired(), EmbedSupported()
  */
  bool GetEmbed() const { return m_embed; }

  /// Set subset flag 
  /**
  * Enables or disables subsetting for the font. Subsetting can be enabled if and only if
  * the font allows subsetting.
  * \param subset indicates whether to subset or not subset the font
  * \see SubsetSupported()
  */
  void SetSubset(bool subset);

  /// Get subset flag
  /**
  * \return TRUE if the font will be subsetted, FALSE otherwise
  * \see SubsetSupported()
  */
  bool GetSubset() const { return m_subset; }

  /// Set encoding
  /**
  * For Type1 and non-Unicode TrueType fonts it is possible to overwrite the default encoding
  * of the font. It's the user's responsibility to ensure the font supports all characters
  * assigned by the encoding.
  * \param encoding the encoding to use with this font
  */
  bool SetEncoding(const wxPdfEncoding& encoding);

  /// Get encoding
  /**
  * For Type1 and non-Unicode TrueType fonts it is possible to overwrite the default encoding
  * of the font. It's the user's responsibility to ensure the font supports all characters
  * assigned by the encoding.
  * \param[out] encoding the encoding used with this font
  * \return TRUE if an encoding is associated with the font, FALSE otherwise
  */
  bool GetEncoding(wxPdfEncoding& encoding);

  /// Get list of supported glyph names
  /**
  * For dynamically loaded Type1 fonts the list of supported glyph names is provided.
  * For all other font types this information is not available.
  * \return TRUE if the list of glyph names is available, otherwise FALSE
  */
  bool GetGlyphNames(wxArrayString& glyphNames) const;

private:
  /// Constructor creating a reference to the real font data
  wxPdfFont(wxPdfFontData* fontData, int fontStyle = wxPDF_FONTSTYLE_REGULAR);

  bool           m_embed;     ///< Flag whether the font should be embedded
  bool           m_subset;    ///< Flag whether the font should be subsetted
  int            m_fontStyle; ///< Font style flags
  wxPdfFontData* m_fontData;  ///< Real font data
  wxPdfEncoding* m_encoding;  ///< Font encoding for Type1 fonts

  friend class wxPdfFontExtended;
  friend class wxPdfFontManagerBase;
};

#endif
