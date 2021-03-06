#
# libgphoto2
#

# Project
cmake_minimum_required(VERSION 3.11)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
project(libgphoto2
    VERSION 2.6.0
    DESCRIPTION "The libgphoto2 camera access and control library."
    HOMEPAGE_URL "https://github.com/gphoto/libgphoto2"
    LANGUAGES C
)

# General options
option(BUILD_SHARED "Build shared libraries." ON)
option(BUILD_STATIC "Build static libraries." OFF)
if (NOT BUILD_SHARED AND NOT BUILD_STATIC)
    message(WARNING "Both shared and static libraries were disabled!")
endif ()
option(BUILD_TESTING "Build tests." OFF)
option(BUILD_GPL "Build GPL licensed camera libraries in addition to LGPL licensed libraries." ON)

# Library names
set(BUILD_LIBGPHOTO2_NAME "gphoto2" CACHE STRING "Name of the ${PROJECT_NAME} library file.")
set(BUILD_LIBGPHOTO2_PORT_NAME "gphoto2_port" CACHE STRING "Name of the ${PROJECT_NAME}_port library file.")

# Camera options
option(BUILD_CAMERA_ADC65 "Build adc65 (Achiever Digital Camera ADC-65 camera) support (GPL2)." ON)
option(BUILD_CAMERA_AGFA_CL20 "Build agfa-cl20 (Agfa ePhoto CL20 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_AOX "Build aox (Concord EyeQMini, D-MAX DM3588 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_AX203 "Build ax203 (Appotech AX203 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_BARBIE "Build barbie (Mattel Barbie, Nick Click, WWF, Hot Wheels cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_CANON "Build canon (older Canon PowerShot and EOS cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_CASIO "Build casio (Casio QV series cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_CLICKSMART310 "Build clicksmart310 (Logitech Clicksmart 310 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_DIGIGR8 "Build digigr8 (S&Q Technologies 9xxx series cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_DIGITA "Build digita (Kodak DC-220, DC-260, DC-265, DC-290 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_DIMERA "Build dimera (Mustek VDC 3500 and Relisys Dimera 3500 cameras) support (???)." ON)
option(BUILD_CAMERA_DIRECTORY "Build directory support (LGPL2)." ON)
option(BUILD_CAMERA_ENIGMA13 "Build enigma13 (Digital Dream Enigma camera) support (LGPL2)." ON)
option(BUILD_CAMERA_FUJI "Build fuji (Fujifilm DS/DX/MX, Apple QuickTake, Samsung Kenox and Leica Digilux cameras) support (GPL2)." ON)
option(BUILD_CAMERA_GSMART300 "Build gsmart300 (Mustek gSmart 300 and Casio LV-10 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_HP215 "Build hp215 (HP Photosmart 215 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_ICLICK "Build iclick (iClick Pro 5X camera) support (LGPL2)." ON)
option(BUILD_CAMERA_JAMCAM "Build jamcam (KBGear JamCam cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_JD11 "Build jd11 (JenOptik JD11, Praktica QD500, Quark Probe, Argus DX-xxx, Digitaldream and IOMagic cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_JL2005A "Build jl2005a (Jeilin JL2005A camera) support (LGPL2)." ON)
option(BUILD_CAMERA_JL2005C "Build jl2005c (Jeilin JL2005B/C/D cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_KODAK_DC120 "Build kodak-dc120 (Kodak DC-120 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_KODAK_DC210 "Build kodak-dc210 (Kodak DC-200, DC-210 and DC-215 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_KODAK_DC240 "Build kodak-dc240 (Kodak DC-240, DC-280, DC-3400, DC-5000 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_KODAK_DC3200 "Build kodak-dc3200 (Kodak DC-3200 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_KODAK_EZ200 "Build kodak-ez200 (Kodak EX-200 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_KONICA "Build konica (HP PhotoSmart Cxxx and Konica Q-xxx cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_KONICA_QM150 "Build konica-qm150 (Konica Q-M150 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_LARGAN_LMINI "Build largan-lmini (Largan Lmini) support (LGPL2)." ON)
option(BUILD_CAMERA_LG_GSM "Build lg-gsm (LG T5100 phone camera) support (LGPL2)." ON)
option(BUILD_CAMERA_LUMIX "Build lumix (Panasonic Lumix G series cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_MARS "Build mars (Mars MR97310 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_MINOLTA_DIMAGEV "Build minolta-dimagev (Minolta Dimage V camera) support (GPL2)." ON)
option(BUILD_CAMERA_MUSTEK "Build mustek (Mustek MDC 800 cameras) support (GPL2)." ON)
option(BUILD_CAMERA_PANASONIC_COOLSHOT "Build panasonic-coolshot (Panasonic KXL-600A and KXL-601A cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_PANASONIC_DC1000 "Build panasonic-dc1000 (Panasonic PV-DC1000 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_PANASONIC_DC1580 "Build panasonic-dc1580 (Panasonic PV-DC1580 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_PANASONIC_L859 "Build panasonic-l859 (Panasonic PV-L859-K/PV-L779-K Palmcorder) support (LGPL2)." ON)
option(BUILD_CAMERA_PCCAM300 "Build pccam300 (Creative PC-CAM 300 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_PCCAM600 "Build pccam600 (Creative PC-CAM 600 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_PENTAX "Build pentax (Pentax Kxxx cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_POLAROID_PDC320 "Build polaroid-pdc320 (Polaroid PDC320 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_POLAROID_PDC640 "Build polaroid-pdc640 (Polaroid PDC640 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_POLAROID_PDC700 "Build polaroid-pdc700 (Polaroid PDC700 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_PTP2 "Build ptp2 (Picture Transfer Protocol) support (LGPL2)." ON)
option(BUILD_CAMERA_RICOH "Build ricoh (Ricoh RDC-xxx and Philips ESPxxx cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_RICOH_G3 "Build ricoh-g3 (Ricoh Caplio and MD series cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_SAMSUNG "Build samsung (Samsung Digimax 800K, Dynatron Dynacam 800, JenOptik JD12 and Praktica QD800 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_SIERRA "Build sierra (older Agfa, Epson, Nikon, Olympus, Panasonic, Pentax, Polaroid, Sanyo, Sierra, Toshiba cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_SIPIX_BLINK "Build sipix-blink (SiPix Blink camera) support (LGPL2)." ON)
option(BUILD_CAMERA_SIPIX_BLINK2 "Build sipix-blink2 (SiPix Blink2 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_SIPIX_WEB2 "Build sipix-web2 (SiPix Web2 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_SMAL "Build smal (Smal Ultrapocket camera) support (LGPL2)." ON)
option(BUILD_CAMERA_SONIX "Build sonix (Sakar Digital, Wild Planet Digital, Mini Shotz, Vivitar and Genius Smart cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_SONYDSCF1 "Build sonydscf1 (Sony DSC-F1 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_SONYDSCF55 "Build sonydscf55 (Sony DSC-F55 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_SOUNDVISION "Build soundvision (Sound Vision cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_SPCA50X "Build spca50x (SunPlus SPCA50x cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_SQ905 "Build sq905 (S&Q Technologies SQ905 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_ST2205 "Build st2205 (Sitronix ST2205 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_STV0674 "Build stv0674 (ST Microelectronics STV0674 cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_STV0680 "Build stv0680 (ST Microelectronics STV0680 cameras) support (GPL2)." ON)
option(BUILD_CAMERA_SX330Z "Build sx330z (Traveler SXxxx, Maginon SXxxx, Skanhex SX-xxx, Medion MD xxx, Jenoptik JD-xxx, Concord and Lifetec cameras) support (LGPL2)." ON)
option(BUILD_CAMERA_TOPFIELD "Build topfield (Topfield TF5000PVR camera) support (GPL2)." ON)
option(BUILD_CAMERA_TOSHIBA_PDRM11 "Build toshiba-pdrm11 (Toshiba PDR-M11 camera) support (LGPL2)." ON)
option(BUILD_CAMERA_TP6801 "Build tp6801 (Tenx TP6801 cameras) support (LGPL2)." ON)
if (NOT BUILD_GPL)
    if (BUILD_CAMERA_ADC65)
        message(WARNING "Camera library 'adc65' cannot be built as GPL licensed code was disabled!")
        set(BUILD_CAMERA_ADC65 FALSE)
    endif ()
    if (BUILD_CAMERA_FUJI)
        message(WARNING "Camera library 'fuji' cannot be built as GPL licensed code was disabled!")
        set(BUILD_CAMERA_FUJI FALSE)
    endif ()
    if (BUILD_CAMERA_MINOLTA_DIMAGEV)
        message(WARNING "Camera library 'minolta-dimagev' cannot be built as GPL licensed code was disabled!")
        set(BUILD_CAMERA_MINOLTA_DIMAGEV FALSE)
    endif ()
    if (BUILD_CAMERA_MUSTEK)
        message(WARNING "Camera library 'mustek' cannot be built as GPL licensed code was disabled!")
        set(BUILD_CAMERA_MUSTEK FALSE)
    endif ()
    if (BUILD_CAMERA_STV0680)
        message(WARNING "Camera library 'stv0680' cannot be built as GPL licensed code was disabled!")
        set(BUILD_CAMERA_STV0680 FALSE)
    endif ()
    if (BUILD_CAMERA_TOPFIELD)
        message(WARNING "Camera library 'topfield' cannot be built as GPL licensed code was disabled!")
        set(BUILD_CAMERA_TOPFIELD FALSE)
    endif ()
endif ()

# Port options
option(BUILD_PORT_DISK "Build disk port support." ON)
option(BUILD_PORT_PTPIP "Build ptpip port support." ON)
option(BUILD_PORT_SERIAL "Build serial port support." ON)
option(BUILD_PORT_LIBUSB1 "Build libusb1 port support." ON)
option(BUILD_PORT_RAWUSB "Build rawusb port support (deprecated in favor of libusb1)." OFF)
option(BUILD_PORT_USBDISKDIRECT "Build usbdiskdirect port support." ON)
option(BUILD_PORT_USBSCSI "Build usbscsi port support." ON)

# Tools
include(tools-cmake)
include(tools-compilers)

# Dependencies
include(libs-avahi)
include(libs-gettext)
include(libs-iconv)
include(libs-intl)
include(libs-curl)
include(libs-libexif)
include(libs-libgd)
include(libs-libjpeg)
include(libs-libusb)
include(libs-libxml2)
include(libs-lockdev)
include(libs-system)

# Libraries
add_subdirectory(camlibs)
add_subdirectory(libgphoto2)
add_subdirectory(libgphoto2_port)
add_subdirectory(tests)

# Print configuration
string(JOIN ", " LIBGPHOTO2_CAMERA_PLUGINS_STRING ${LIBGPHOTO2_CAMERA_PLUGINS})
string(JOIN ", " LIBGPHOTO2_PORT_PLUGINS_STRING ${LIBGPHOTO2_PORT_PLUGINS})
message(STATUS "Selected camera libraries: ${LIBGPHOTO2_CAMERA_PLUGINS_STRING}")
message(STATUS "Selected port libraries: ${LIBGPHOTO2_PORT_PLUGINS_STRING}")
