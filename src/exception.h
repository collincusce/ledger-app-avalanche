#pragma once

#include "os.h"

// Throw this to indicate prompting
#define ASYNC_EXCEPTION 0x2000

// Standard APDU error codes:
// https://www.eftlab.co.uk/index.php/site-map/knowledge-base/118-apdu-response-list

#define EXC_WRONG_PARAM               0x6B00
#define EXC_WRONG_LENGTH              0x6C00
#define EXC_INVALID_INS               0x6D00
#define EXC_WRONG_LENGTH_FOR_INS      0x917E
#define EXC_REJECT                    0x6985
#define EXC_PARSE_ERROR               0x9405
#define EXC_REFERENCED_DATA_NOT_FOUND 0x6A88
#define EXC_WRONG_VALUES              0x6A80
#define EXC_SECURITY                  0x6982
#define EXC_HID_REQUIRED              0x6983
#define EXC_CLASS                     0x6E00
#define EXC_MEMORY_ERROR              0x9200
#define EXC_STACK_ERROR               0xA000

// Like THROW but with PRINTF debugging built in.
#define THROW_(exc, str, ...) { \
        PRINTF("THROWING %d on line %d: ", exc, __LINE__); PRINTF(str "\n", ##__VA_ARGS__); \
        THROW(exc); \
    }

// Crashes can be harder to debug than exceptions and latency isn't a big concern
static inline void check_null(void volatile const *const ptr) {
    if (ptr == NULL) {
        THROW(EXC_MEMORY_ERROR);
    }
}
