#include "prj_cfg.h"
#include "DRE.h"
#include "prj_pinout.h"

// --- DRE data structure declaration ---
t_dre dre;
#ifdef _DIAG_ACTIVE
t_diag diag;
#endif

/// Inputs

void setup_S1Sense(void) {
    pinMode(PORT_S1Sense, INPUT);
};

void acquire_S1Sense(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_S1Sense) {
        dre.S1Sense = diag.S1Sense;
    } else {
#endif
        dre.S1Sense = analogRead(PORT_S1Sense);
#ifdef _DIAG_ACTIVE
    }
#endif
}

void setup_BATSense(void) {
    pinMode(PORT_BATSense, INPUT);
};

void acquire_BATSense(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_BATSense) {
        dre.BATSense = diag.BATSense;
    } else {
#endif
        dre.BATSense = analogRead(PORT_BATSense);
#ifdef _DIAG_ACTIVE
    }
#endif
}

void setup_BUTRaw(void) {
    pinMode(PORT_BUTRaw, INPUT_PULLUP);
};

void acquire_BUTRaw(void) {
#ifdef _DIAG_ACTIVE
    if (diag.enable_BUTRaw) {
        dre.BUTRaw = diag.BUTRaw;
    } else {
#endif
        dre.BUTRaw = (digitalRead(PORT_BUTRaw) == LOW);
#ifdef _DIAG_ACTIVE
    }
#endif
}


/// Internals

void setup_S1Mode(void) {
    dre.S1Mode = S1_NORMAL_IDX;
}

void setup_BATMode(void) {
    dre.BATMode = BAT_NORMAL_IDX;
}

void setup_BUTFilt(void) {
    dre.BUTFilt = false;
}


/// Outputs

void setup_ledStatus(void) {
    pinMode(PORT_ledStatus, OUTPUT);
}


/* Note: the status led can be used to debug the button Input or the
program cycle (using a blink function).  Definitions DEBUG_BUT and
DEBUG_BLINK override the normal behaviour.  In normal mode, the led
follows the ledStatus DRE variable */
void synthesize_ledStatus(void) {
#ifdef DEBUG_BUT
    digitalWrite(PORT_ledStatus, dre.BUTFilt);
#else
#ifdef DEBUG_BLINK
    digitalWrite(PORT_ledStatus, dre.blink.led);
#else
    bool aux;
#ifdef _DIAG_ACTIVE
    if (diag.enable_ledStatus) {
        aux = diag.ledStatus;
    } else {
#endif
        aux = dre.ledStatus;
#ifdef _DIAG_ACTIVE
    }
#endif
    if (aux){
        digitalWrite(PORT_ledStatus, LOW);
    } else {
        digitalWrite(PORT_ledStatus, HIGH);
    }
#endif
#endif
};


/// Structure initialization

void dreInit(void) {
    setup_S1Mode();
    setup_BATMode();
    setup_BUTFilt();
}
