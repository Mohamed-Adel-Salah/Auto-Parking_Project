/*
 * DC_Motor.h
 *
 *  Created on: Sep 16, 2023
 *      Author: Owner
 */

#ifndef INC_DC_MOTOR_H_
#define INC_DC_MOTOR_H_

#define  Stop					'S'
#define  Forward 				'F'
#define  Backward 				'B'
#define  Turn_leftforward  		'G'
#define  Turn_leftbackward 		'H'
#define  Turn_rightforward		'I'
#define  Turn_rightbackward		'J'
#define  Auto_Parking    		'P'


void move_Forward (void);
void move_backward (void);
void turn_right_forward (void);
void turn_right_backward (void);
void turn_left_forward (void);
void turn_left_backward (void);
void stop (void);

void SET_PULSE(uint32_t pulse);
extern uint8_t STATE ;

#endif /* INC_DC_MOTOR_H_ */
