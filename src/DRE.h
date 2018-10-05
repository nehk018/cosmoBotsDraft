#ifndef _DRE_H
#define _DRE_H

#include "prj_types.h"

#include "S1Mode/S1ModePrj.h"
#include "BATMode/BATModePrj.h"

/// Blink function structure
typedef struct {
    bool led;
    uint16_t timer;
}t_blink_function;


/// DRE Structure
typedef struct {
    /// Inputs
    uint16_t s1Sense;
    uint16_t batSense;

    /// Internals
    t_enum_s1Mode s1Mode;
    t_enum_batMode batMode;

    /// Outputs
    bool ledStatus;
    
    /// Functions
    t_blink_function blink;
} t_dre;

/// Blink function diagnostics structure
#ifdef _DIAG_ACTIVE
typedef struct {
    bool enable_led;
    bool led;
    bool enable_timer;
    uint16_t timer;
}t_blink_function_diag;

/// Diagnostics DRE structure
typedef struct {
    bool enable_ledStatus;
    bool ledStatus;
    bool enable_s1Sense;
    uint16_t s1Sense;
    bool enable_s1Mode;
    t_enum_s1Mode s1Mode;
    bool enable_batSense;
    uint16_t batSense;
    bool enable_batMode;
    t_enum_batMode batMode;
    t_blink_function_diag blink;
} t_diag;
#endif

// Initialization functions

/// Inputs
void setup_s1Sense(void);
void acquire_s1Sense(void);
void setup_batSense(void);
void acquire_batSense(void);

/// Internals
void setup_s1Mode(void);
void setup_batMode(void);

/// Outputs
void setup_ledStatus(void);
void synthesize_ledStatus(void);

void dreInit(void);

#endif /* _DRE_H */
