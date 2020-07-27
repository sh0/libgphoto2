/** \file
 *
 * \author Copyright 2001 Lutz Mueller <lutz@users.sf.net>
 *
 * \par License
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * \par
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * \par
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include <gphoto2-config.h>
#include <gphoto2/gphoto2-library.h>

/* Camera library declarations. */
#ifdef BUILD_CAMERA_ADC65
extern CameraLibrary camera_adc65_library;
#endif
#ifdef BUILD_CAMERA_AGFA_CL20
extern CameraLibrary camera_agfa_cl20_library;
#endif
#ifdef BUILD_CAMERA_AOX
extern CameraLibrary camera_aox_library;
#endif
#ifdef BUILD_CAMERA_AX203
extern CameraLibrary camera_ax203_library;
#endif
#ifdef BUILD_CAMERA_BARBIE
extern CameraLibrary camera_barbie_library;
#endif
#ifdef BUILD_CAMERA_CANON
extern CameraLibrary camera_canon_library;
#endif
#ifdef BUILD_CAMERA_CASIO
extern CameraLibrary camera_casio_library;
#endif
#ifdef BUILD_CAMERA_CLICKSMART310
extern CameraLibrary camera_clicksmart310_library;
#endif
#ifdef BUILD_CAMERA_DIGIGR8
extern CameraLibrary camera_digigr8_library;
#endif
#ifdef BUILD_CAMERA_DIGITA
extern CameraLibrary camera_digita_library;
#endif
#ifdef BUILD_CAMERA_DIMERA
extern CameraLibrary camera_dimera_library;
#endif
#ifdef BUILD_CAMERA_DIRECTORY
extern CameraLibrary camera_directory_library;
#endif
#ifdef BUILD_CAMERA_ENIGMA13
extern CameraLibrary camera_enigma13_library;
#endif
#ifdef BUILD_CAMERA_FUJI
extern CameraLibrary camera_fuji_library;
#endif
#ifdef BUILD_CAMERA_GSMART300
extern CameraLibrary camera_gsmart300_library;
#endif
#ifdef BUILD_CAMERA_HP215
extern CameraLibrary camera_hp215_library;
#endif
#ifdef BUILD_CAMERA_ICLICK
extern CameraLibrary camera_iclick_library;
#endif
#ifdef BUILD_CAMERA_JAMCAM
extern CameraLibrary camera_jamcam_library;
#endif
#ifdef BUILD_CAMERA_JD11
extern CameraLibrary camera_jd11_library;
#endif
#ifdef BUILD_CAMERA_JL2005A
extern CameraLibrary camera_jl2005a_library;
#endif
#ifdef BUILD_CAMERA_JL2005C
extern CameraLibrary camera_jl2005c_library;
#endif
#ifdef BUILD_CAMERA_KODAK_DC120
extern CameraLibrary camera_kodak_dc120_library;
#endif
#ifdef BUILD_CAMERA_KODAK_DC210
extern CameraLibrary camera_kodak_dc210_library;
#endif
#ifdef BUILD_CAMERA_KODAK_DC240
extern CameraLibrary camera_kodak_dc240_library;
#endif
#ifdef BUILD_CAMERA_KODAK_DC3200
extern CameraLibrary camera_kodak_dc3200_library;
#endif
#ifdef BUILD_CAMERA_KODAK_EZ200
extern CameraLibrary camera_kodak_ez200_library;
#endif
#ifdef BUILD_CAMERA_KONICA
extern CameraLibrary camera_konica_library;
#endif
#ifdef BUILD_CAMERA_KONICA_QM150
extern CameraLibrary camera_konica_qm150_library;
#endif
#ifdef BUILD_CAMERA_LARGAN_LMINI
extern CameraLibrary camera_largan_lmini_library;
#endif
#ifdef BUILD_CAMERA_LG_GSM
extern CameraLibrary camera_lg_gsm_library;
#endif
#ifdef BUILD_CAMERA_LUMIX
extern CameraLibrary camera_lumix_library;
#endif
#ifdef BUILD_CAMERA_MARS
extern CameraLibrary camera_mars_library;
#endif
#ifdef BUILD_CAMERA_MINOLTA_DIMAGEV
extern CameraLibrary camera_minolta_dimagev_library;
#endif
#ifdef BUILD_CAMERA_MUSTEK
extern CameraLibrary camera_mustek_library;
#endif
#ifdef BUILD_CAMERA_PANASONIC_COOLSHOT
extern CameraLibrary camera_panasonic_coolshot_library;
#endif
#ifdef BUILD_CAMERA_PANASONIC_DC1000
extern CameraLibrary camera_panasonic_dc1000_library;
#endif
#ifdef BUILD_CAMERA_PANASONIC_DC1580
extern CameraLibrary camera_panasonic_dc1580_library;
#endif
#ifdef BUILD_CAMERA_PANASONIC_L859
extern CameraLibrary camera_panasonic_l859_library;
#endif
#ifdef BUILD_CAMERA_PCCAM300
extern CameraLibrary camera_pccam300_library;
#endif
#ifdef BUILD_CAMERA_PCCAM600
extern CameraLibrary camera_pccam600_library;
#endif
#ifdef BUILD_CAMERA_PENTAX
extern CameraLibrary camera_pentax_library;
#endif
#ifdef BUILD_CAMERA_POLAROID_PDC320
extern CameraLibrary camera_polaroid_pdc320_library;
#endif
#ifdef BUILD_CAMERA_POLAROID_PDC640
extern CameraLibrary camera_polaroid_pdc640_library;
#endif
#ifdef BUILD_CAMERA_POLAROID_PDC700
extern CameraLibrary camera_polaroid_pdc700_library;
#endif
#ifdef BUILD_CAMERA_PTP2
extern CameraLibrary camera_ptp2_library;
#endif
#ifdef BUILD_CAMERA_RICOH_G3
extern CameraLibrary camera_ricoh_g3_library;
#endif
#ifdef BUILD_CAMERA_RICOH
extern CameraLibrary camera_ricoh_library;
#endif
#ifdef BUILD_CAMERA_SAMSUNG
extern CameraLibrary camera_samsung_library;
#endif
#ifdef BUILD_CAMERA_SIERRA
extern CameraLibrary camera_sierra_library;
#endif
#ifdef BUILD_CAMERA_SIPIX_BLINK2
extern CameraLibrary camera_sipix_blink2_library;
#endif
#ifdef BUILD_CAMERA_SIPIX_BLINK
extern CameraLibrary camera_sipix_blink_library;
#endif
#ifdef BUILD_CAMERA_SIPIX_WEB2
extern CameraLibrary camera_sipix_web2_library;
#endif
#ifdef BUILD_CAMERA_SMAL
extern CameraLibrary camera_smal_library;
#endif
#ifdef BUILD_CAMERA_SONIX
extern CameraLibrary camera_sonix_library;
#endif
#ifdef BUILD_CAMERA_SONYDSCF1
extern CameraLibrary camera_sonydscf1_library;
#endif
#ifdef BUILD_CAMERA_SONYDSCF55
extern CameraLibrary camera_sonydscf55_library;
#endif
#ifdef BUILD_CAMERA_SOUNDVISION
extern CameraLibrary camera_soundvision_library;
#endif
#ifdef BUILD_CAMERA_SPCA50X
extern CameraLibrary camera_spca50x_library;
#endif
#ifdef BUILD_CAMERA_SQ905
extern CameraLibrary camera_sq905_library;
#endif
#ifdef BUILD_CAMERA_ST2205
extern CameraLibrary camera_st2205_library;
#endif
#ifdef BUILD_CAMERA_STV0674
extern CameraLibrary camera_stv0674_library;
#endif
#ifdef BUILD_CAMERA_STV0680
extern CameraLibrary camera_stv0680_library;
#endif
#ifdef BUILD_CAMERA_SX330Z
extern CameraLibrary camera_sx330z_library;
#endif
#ifdef BUILD_CAMERA_TOPFIELD
extern CameraLibrary camera_topfield_library;
#endif
#ifdef BUILD_CAMERA_TOSHIBA_PDRM11
extern CameraLibrary camera_toshiba_pdrm11_library;
#endif
#ifdef BUILD_CAMERA_TP6801
extern CameraLibrary camera_tp6801_library;
#endif

/* List of internal camera libraries. */
static CameraLibrary* gpi_libraries[] = {
#ifdef BUILD_CAMERA_ADC65
    &camera_adc65_library,
#endif
#ifdef BUILD_CAMERA_AGFA_CL20
    &camera_agfa_cl20_library,
#endif
#ifdef BUILD_CAMERA_AOX
    &camera_aox_library,
#endif
#ifdef BUILD_CAMERA_AX203
    &camera_ax203_library,
#endif
#ifdef BUILD_CAMERA_BARBIE
    &camera_barbie_library,
#endif
#ifdef BUILD_CAMERA_CANON
    &camera_canon_library,
#endif
#ifdef BUILD_CAMERA_CASIO
    &camera_casio_library,
#endif
#ifdef BUILD_CAMERA_CLICKSMART310
    &camera_clicksmart310_library,
#endif
#ifdef BUILD_CAMERA_DIGIGR8
    &camera_digigr8_library,
#endif
#ifdef BUILD_CAMERA_DIGITA
    &camera_digita_library,
#endif
#ifdef BUILD_CAMERA_DIMERA
    &camera_dimera_library,
#endif
#ifdef BUILD_CAMERA_DIRECTORY
    &camera_directory_library,
#endif
#ifdef BUILD_CAMERA_ENIGMA13
    &camera_enigma13_library,
#endif
#ifdef BUILD_CAMERA_FUJI
    &camera_fuji_library,
#endif
#ifdef BUILD_CAMERA_GSMART300
    &camera_gsmart300_library,
#endif
#ifdef BUILD_CAMERA_HP215
    &camera_hp215_library,
#endif
#ifdef BUILD_CAMERA_ICLICK
    &camera_iclick_library,
#endif
#ifdef BUILD_CAMERA_JAMCAM
    &camera_jamcam_library,
#endif
#ifdef BUILD_CAMERA_JD11
    &camera_jd11_library,
#endif
#ifdef BUILD_CAMERA_JL2005A
    &camera_jl2005a_library,
#endif
#ifdef BUILD_CAMERA_JL2005C
    &camera_jl2005c_library,
#endif
#ifdef BUILD_CAMERA_KODAK_DC120
    &camera_kodak_dc120_library,
#endif
#ifdef BUILD_CAMERA_KODAK_DC210
    &camera_kodak_dc210_library,
#endif
#ifdef BUILD_CAMERA_KODAK_DC240
    &camera_kodak_dc240_library,
#endif
#ifdef BUILD_CAMERA_KODAK_DC3200
    &camera_kodak_dc3200_library,
#endif
#ifdef BUILD_CAMERA_KODAK_EZ200
    &camera_kodak_ez200_library,
#endif
#ifdef BUILD_CAMERA_KONICA
    &camera_konica_library,
#endif
#ifdef BUILD_CAMERA_KONICA_QM150
    &camera_konica_qm150_library,
#endif
#ifdef BUILD_CAMERA_LARGAN_LMINI
    &camera_largan_lmini_library,
#endif
#ifdef BUILD_CAMERA_LG_GSM
    &camera_lg_gsm_library,
#endif
#ifdef BUILD_CAMERA_LUMIX
    &camera_lumix_library,
#endif
#ifdef BUILD_CAMERA_MARS
    &camera_mars_library,
#endif
#ifdef BUILD_CAMERA_MINOLTA_DIMAGEV
    &camera_minolta_dimagev_library,
#endif
#ifdef BUILD_CAMERA_MUSTEK
    &camera_mustek_library,
#endif
#ifdef BUILD_CAMERA_PANASONIC_COOLSHOT
    &camera_panasonic_coolshot_library,
#endif
#ifdef BUILD_CAMERA_PANASONIC_DC1000
    &camera_panasonic_dc1000_library,
#endif
#ifdef BUILD_CAMERA_PANASONIC_DC1580
    &camera_panasonic_dc1580_library,
#endif
#ifdef BUILD_CAMERA_PANASONIC_L859
    &camera_panasonic_l859_library,
#endif
#ifdef BUILD_CAMERA_PCCAM300
    &camera_pccam300_library,
#endif
#ifdef BUILD_CAMERA_PCCAM600
    &camera_pccam600_library,
#endif
#ifdef BUILD_CAMERA_PENTAX
    &camera_pentax_library,
#endif
#ifdef BUILD_CAMERA_POLAROID_PDC320
    &camera_polaroid_pdc320_library,
#endif
#ifdef BUILD_CAMERA_POLAROID_PDC640
    &camera_polaroid_pdc640_library,
#endif
#ifdef BUILD_CAMERA_POLAROID_PDC700
    &camera_polaroid_pdc700_library,
#endif
#ifdef BUILD_CAMERA_PTP2
    &camera_ptp2_library,
#endif
#ifdef BUILD_CAMERA_RICOH_G3
    &camera_ricoh_g3_library,
#endif
#ifdef BUILD_CAMERA_RICOH
    &camera_ricoh_library,
#endif
#ifdef BUILD_CAMERA_SAMSUNG
    &camera_samsung_library,
#endif
#ifdef BUILD_CAMERA_SIERRA
    &camera_sierra_library,
#endif
#ifdef BUILD_CAMERA_SIPIX_BLINK2
    &camera_sipix_blink2_library,
#endif
#ifdef BUILD_CAMERA_SIPIX_BLINK
    &camera_sipix_blink_library,
#endif
#ifdef BUILD_CAMERA_SIPIX_WEB2
    &camera_sipix_web2_library,
#endif
#ifdef BUILD_CAMERA_SMAL
    &camera_smal_library,
#endif
#ifdef BUILD_CAMERA_SONIX
    &camera_sonix_library,
#endif
#ifdef BUILD_CAMERA_SONYDSCF1
    &camera_sonydscf1_library,
#endif
#ifdef BUILD_CAMERA_SONYDSCF55
    &camera_sonydscf55_library,
#endif
#ifdef BUILD_CAMERA_SOUNDVISION
    &camera_soundvision_library,
#endif
#ifdef BUILD_CAMERA_SPCA50X
    &camera_spca50x_library,
#endif
#ifdef BUILD_CAMERA_SQ905
    &camera_sq905_library,
#endif
#ifdef BUILD_CAMERA_ST2205
    &camera_st2205_library,
#endif
#ifdef BUILD_CAMERA_STV0674
    &camera_stv0674_library,
#endif
#ifdef BUILD_CAMERA_STV0680
    &camera_stv0680_library,
#endif
#ifdef BUILD_CAMERA_SX330Z
    &camera_sx330z_library,
#endif
#ifdef BUILD_CAMERA_TOPFIELD
    &camera_topfield_library,
#endif
#ifdef BUILD_CAMERA_TOSHIBA_PDRM11
    &camera_toshiba_pdrm11_library,
#endif
#ifdef BUILD_CAMERA_TP6801
    &camera_tp6801_library,
#endif
    NULL
};

CameraLibrary** gp_camera_libraries_list()
{
    return gpi_libraries;
}
