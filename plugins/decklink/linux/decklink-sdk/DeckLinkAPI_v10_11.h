/* -LICENSE-START-
** Copyright (c) 2018 Blackmagic Design
**
** Permission is hereby granted, free of charge, to any person or organization
** obtaining a copy of the software and accompanying documentation covered by
** this license (the "Software") to use, reproduce, display, distribute,
** execute, and transmit the Software, and to prepare derivative works of the
** Software, and to permit third-parties to whom the Software is furnished to
** do so, all subject to the following:
** 
** The copyright notices in the Software and this entire statement, including
** the above license grant, this restriction and the following disclaimer,
** must be included in all copies of the Software, in whole or in part, and
** all derivative works of the Software, unless such copies or derivative
** works are solely in the form of machine-executable object code generated by
** a source language processor.
** 
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
** -LICENSE-END-
*/

#ifndef BMD_DECKLINKAPI_v10_11_H
#define BMD_DECKLINKAPI_v10_11_H

#include "DeckLinkAPI.h"

// Interface ID Declarations

BMD_CONST REFIID IID_IDeckLinkAttributes_v10_11                     = /* ABC11843-D966-44CB-96E2-A1CB5D3135C4 */ {0xAB,0xC1,0x18,0x43,0xD9,0x66,0x44,0xCB,0x96,0xE2,0xA1,0xCB,0x5D,0x31,0x35,0xC4};
BMD_CONST REFIID IID_IDeckLinkNotification_v10_11                   = /* 0A1FB207-E215-441B-9B19-6FA1575946C5 */ {0x0A,0x1F,0xB2,0x07,0xE2,0x15,0x44,0x1B,0x9B,0x19,0x6F,0xA1,0x57,0x59,0x46,0xC5};

/* Enum BMDDisplayModeSupport_v10_11 - Output mode supported flags */

typedef uint32_t BMDDisplayModeSupport_v10_11;
enum _BMDDisplayModeSupport_v10_11 {
	bmdDisplayModeNotSupported_v10_11                               = 0,
	bmdDisplayModeSupported_v10_11,
	bmdDisplayModeSupportedWithConversion_v10_11
};

/* Enum BMDDuplexMode_v10_11 - Duplex for configurable ports */

typedef uint32_t BMDDuplexMode_v10_11;
enum _BMDDuplexMode_v10_11 {
    bmdDuplexModeFull_v10_11                                        = /* 'fdup' */ 0x66647570,
    bmdDuplexModeHalf_v10_11                                        = /* 'hdup' */ 0x68647570
};

/* Enum BMDDeckLinkAttributeID_v10_11 - DeckLink Attribute ID */

enum _BMDDeckLinkAttributeID_v10_11 {

    /* Flags */

    BMDDeckLinkSupportsDuplexModeConfiguration_v10_11               = 'dupx',
    BMDDeckLinkSupportsHDKeying_v10_11                              = 'keyh',

    /* Integers */

    BMDDeckLinkPairedDevicePersistentID_v10_11                      = 'ppid',
    BMDDeckLinkSupportsFullDuplex_v10_11                            = 'fdup',
};

enum  _BMDDeckLinkStatusID_v10_11 {
    bmdDeckLinkStatusDuplexMode_v10_11                             = 'dupx',
};

typedef uint32_t BMDDuplexStatus_v10_11;
enum _BMDDuplexStatus_v10_11 {
    bmdDuplexFullDuplex_v10_11                                      = 'fdup',
    bmdDuplexHalfDuplex_v10_11                                      = 'hdup',
    bmdDuplexSimplex_v10_11                                         = 'splx',
    bmdDuplexInactive_v10_11                                        = 'inac',
};

#if defined(__cplusplus)

/* Interface IDeckLinkAttributes_v10_11 - DeckLink Attribute interface */

class BMD_PUBLIC IDeckLinkAttributes_v10_11 : public IUnknown
{
public:
    virtual HRESULT GetFlag (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ bool *value) = 0;
    virtual HRESULT GetInt (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ int64_t *value) = 0;
    virtual HRESULT GetFloat (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ double *value) = 0;
    virtual HRESULT GetString (/* in */ BMDDeckLinkAttributeID cfgID, /* out */ const char **value) = 0;

protected:
    virtual ~IDeckLinkAttributes_v10_11 () {} // call Release method to drop reference count
};

/* Interface IDeckLinkNotification_v10_11 - DeckLink Notification interface */

class BMD_PUBLIC IDeckLinkNotification_v10_11 : public IUnknown
{
public:
    virtual HRESULT Subscribe (/* in */ BMDNotifications topic, /* in */ IDeckLinkNotificationCallback *theCallback) = 0;
    virtual HRESULT Unsubscribe (/* in */ BMDNotifications topic, /* in */ IDeckLinkNotificationCallback *theCallback) = 0;
};

/* Functions */

extern "C" {

    IDeckLinkIterator* BMD_PUBLIC CreateDeckLinkIteratorInstance_v10_11 (void);
    IDeckLinkDiscovery* BMD_PUBLIC CreateDeckLinkDiscoveryInstance_v10_11 (void);
    IDeckLinkAPIInformation* BMD_PUBLIC CreateDeckLinkAPIInformationInstance_v10_11 (void);
    IDeckLinkGLScreenPreviewHelper* BMD_PUBLIC CreateOpenGLScreenPreviewHelper_v10_11 (void);
    IDeckLinkVideoConversion* BMD_PUBLIC CreateVideoConversionInstance_v10_11 (void);
    IDeckLinkVideoFrameAncillaryPackets* BMD_PUBLIC CreateVideoFrameAncillaryPacketsInstance_v10_11 (void); // For use when creating a custom IDeckLinkVideoFrame without wrapping IDeckLinkOutput::CreateVideoFrame

}

#endif      // defined(__cplusplus)
#endif /* defined(BMD_DECKLINKAPI_v10_11_H) */
