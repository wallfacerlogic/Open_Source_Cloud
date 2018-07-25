#include "ASEIO.h"






void main()

{

    WER_InitRobot_5(0,1.000000,1,1.000000,0,2,3,4,6,0,0.500000,1,1);

    WER_next();		

    WER_SetMotor(100,100,0.200);

    WER_LineWay_C(1,0,100,1,1,1,0.200);

    WER_Around(-60,60,1,1,0);

    WER_LineWay_C(1,1,100,20,20,1,0.200);

    WER_Around(60,-60,1,1,0);

    BEEP(523.200012,0.500000);

    WER_LineWay_C(1,0,100,50,50,1,0.300);

    WER_Around(-60,60,1,1,0);

    WER_LineWay_C(1,1,100,20,20,1,0.200);

    WER_Around(60,-60,1,1,0);

    WER_LineWay_C(1,1,100,20,20,1,0.200);

    WER_Around(60,-60,1,1,0);

    WER_LineWay_C(1,1,100,40,40,1,0.250);

    WER_Around(60,-60,1,1,0);

    WER_LineWay_C(1,0,100,20,20,1,0.200);

    WER_Around(-60,60,1,1,0);

    WER_LineWay_T(100,40,40,1,0.400);

    WER_SetMotor(100,100,0.800);

    WER_LineWay_C(1,1,100,45,45,1,0.250);

    WER_Around(60,-60,1,1,0);

    WER_LineWay_C(1,0,100,40,40,1,0.200);

    WER_Around(0,60,1,1,0);

    WER_LineWay_C(1,1,100,40,40,1,0.200);

    WER_Around(60,0,1,1,0);

    WER_LineWay_C(1,0,100,60,60,1,0.200);

    WER_Around(-60,60,1,1,0);

    WER_LineWay_C(1,0,100,20,20,1,0.200);
 
    WER_Around(-60,60,1,1,0);

    WER_LineWay_T(100,40,40,1,0.200);

    WER_SetMotor_L(0,">=",2500,60,60,1);

    WER_Around(-60,60,1,1,0);

    WER_LineWay_T(100,40,40,1,0.500);

    WER_SetMotor_L(0,">=",2500,60,60,1);

    BEEP(587.299988,0.500000);

    WER_Around(-60,60,1,1,0);

    WER_SetMotor(-60,60,0.010);

    BEEP(698.400024,0.500000);

    WER_SetMotor(20,20,4.000);

    BEEP(659.200012,0.500000);

    WER_LineWay_T(100,30,30,1,0.800);

    WER_SetMotor(100,100,0.300);

    WER_LineWay_C(1,1,100,50,50,1,0.250);

    WER_Around(60,-60,1,1,0);

    WER_LineWay_C(1,0,100,50,50,1,0.250);

    WER_Around(-60,60,1,1,0);

    WER_LineWay_C(1,1,100,50,50,1,0.250);
 
    WER_Around(60,-60,1,1,0);

    WER_LineWay_C(1,1,100,20,20,1,0.250);

    WER_Around(60,-60,1,1,0);

    WER_LineWay_C(1,0,100,20,20,1,0.300);

    WER_Around(-60,60,1,1,0);

    WER_LineWay_C(1,0,100,20,20,1,0.300);

    WER_Around(-60,60,1,1,0);

    WER_LineWay_C(1,1,100,20,20,1,0.300);

    BEEP(523.200012,1.000000);		

    WER_SetMotor(60,-60,0.200);

    WER_Around(60,-60,1,1,0);

    WER_LineWay_C(1,0,100,0,0,1,0.350);

}