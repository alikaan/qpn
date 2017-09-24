/*****************************************************************************
* Model: dpp_comp.qm
* File:  ./dpp.h
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/*${.::dpp.h} ..............................................................*/
#ifndef dpp_h
#define dpp_h

enum DPPSignals {
    EAT_SIG = Q_USER_SIG, /* published by Table to let a philosopher eat */
    DONE_SIG,             /* published by Philosopher when done eating */
    PAUSE_SIG,            /* published by BSP to pause the application */
    SERVE_SIG,            /* published by BSP to pause the application */
    TERMINATE_SIG,        /* published by BSP to terminate the application */
    HUNGRY_SIG,           /* posted direclty to Table from hungry Philo */
    MAX_SIG               /* the last signal */
};

/* number of philosophers */
#define N_PHILO ((uint8_t)10)


#if ((QP_VERSION < 591) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8)))
#error qpn version 5.9.1 or higher required
#endif

/*${AOs::Philo} ............................................................*/
typedef struct Philo {
/* protected: */
    QHsm super;

/* public: */
    uint16_t tickCtr;
    uint8_t num;
} Philo;

/* public: */
void Philo_ctor(Philo * const me, uint8_t num);

/* protected: */
QState Philo_initial(Philo * const me);
QState Philo_thinking(Philo * const me);
QState Philo_hungry(Philo * const me);
QState Philo_eating(Philo * const me);

extern struct Table AO_Table;

/*${AOs::Table_ctor} .......................................................*/
void Table_ctor(void);


#endif /* dpp_h */