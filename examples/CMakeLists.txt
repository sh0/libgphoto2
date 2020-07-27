#
# libgphoto2
#

set(SAMPLE_AFL_SOURCES sample-afl.c samples.h context.c autodetect.c)
set(SAMPLE_AUTODETECT_SOURCES sample-autodetect.c samples.h context.c config.c)
set(SAMPLE_OWNER_SOURCES sample-owner.c samples.h context.c config.c)
set(SAMPLE_MULTI_DETECT_SOURCES sample-multi-detect.c samples.h autodetect.c context.c config.c)
set(LUNKWILL_CANON_CAPTURE_SOURCES lunkwill-canon-capture.c context.c samples.h config.c)
set(SAMPLE_CAPTURE_SOURCES sample-capture.c context.c samples.h config.c focus.c)
set(SAMPLE_TRIGGER_CAPTURE_SOURCES sample-trigger-capture.c context.c samples.h config.c)
set(SAMPLE_PHOTOBOOTH_SOURCES sample-photobooth.c samples.h context.c config.c)
set(SAMPLE_PREVIEW_SOURCES preview.c samples.h context.c config.c focus.c)
set(SAMPLE_TETHER_SOURCES samples.h sample-tether.c context.c config.c)
set(BEST_ISO_SOURCES best-iso.c)
set(SAMPLE_JUSTFOCUS_SOURCES samples.h sample-justfocus.c context.c focus.c)
