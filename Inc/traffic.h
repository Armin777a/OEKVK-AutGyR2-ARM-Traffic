//
// Created by Armin on 20-May-23.
//

#ifndef ARM_TRAFFIC_V2_TRAFFIC_H
#define ARM_TRAFFIC_V2_TRAFFIC_H


// Include files
#include "main.h"
#include "leds.h"




//////////////////////////////////////////////////////////////////////////
// Changeable parameters, constants, macros
//////////////////////////////////////////////////////////////////////////

#define ENABLE_DEBUG_MODE				0								// Enable's the debug mode (1 - on, 0 - off) - Print out the master iterator's value to leds


// Set the delays
#define DELAY_All_Red_Start				20								// Timing of the starting state of the modes, where all the light are red (in x*100ms)
#define DELAY_Red						50								// Timing of the main red-green light state (in x*100ms)
#define DELAY_Red_Yellow				10								// Timing of the red-yellow transition light state (in x*100ms)
#define DELAY_Pre_Green_Blink			20								// Timing of the end of the green state where the pedestrian green light starts blinking (in x*100ms)
#define DELAY_Yellow					20								// Timing of the yellow light and blinking pedestrian light (in x*100ms)
#define DELAY_Turn						30								// Timing for the turning lanes (in x*100ms)
#define DELAY_Blink						5								// Dealy between blinks (in x*100ms)
#define DELAY_All_Red					5
#define DELAY_Only_Green				DELAY_Red - DELAY_Pre_Green_Blink	// Calculated value for the state where the pedestrian lights are not yet blinking


// Set the start address of the program
/*
#define PROGRAM_ServiceMode				50								// Service mode's address in the master table
#define PROGRAM_Normal					8								// Normal mode's address in the master table
#define PROGRAM_Normal_All_Red			7								// Normal mode's all red state's address in the master table
#define PROGRAM_Train_All_Red			25								// Train mode's all red state's address in the master table
#define PROGRAM_Train					35								// Train mode's address in the master table
#define PROGRAM_Volatile				5								// Volatile mode's address in the master table
*/
//Set adresses of the program for DEBUG mode
#define PROGRAM_ServiceMode				13								// Service mode's address in the master table
#define PROGRAM_Normal					8								// Normal mode's address in the master table
#define PROGRAM_Normal_All_Red			7								// Normal mode's all red state's address in the master table
#define PROGRAM_Train_All_Red			16								// Train mode's all red state's address in the master table
#define PROGRAM_Train					17								// Train mode's address in the master table
#define PROGRAM_Volatile				5								// Volatile mode's address in the master table




//////////////////////////////////////////////////////////////////////////
// Mostly static constants/macros
//////////////////////////////////////////////////////////////////////////

#define DATA_Traffic_Light_StartID		2								// The first light's ID (column)
#define DATA_Traffic_Light_NextID		4								// The next light's offset from the current one
#define DATA_Port_Line					0								// The line (row) where the lights ports are located
#define DATA_Pin_Line					1								// The line (row) where the lights pins are located
#define DATA_Type_Line					2								// The line (row) where the lights types are located
#define DATA_Lenght						DATA_Traffic_Light_NextID		// Alternate name for the "DATA_Traffic_Light_NextID" when using a for loop
#define MASTERTABLE_NextState			0								// The column where the next states are located
#define MASTERTABLE_Delay				1								// The column where the delays are located (in x*100ms)

#define DATA_Traffic_Red_Offset			0								// Car's red light offset from the light's ID
#define DATA_Traffic_Yellow_Offset		1								// Car's yellow light offset from the light's ID
#define DATA_Traffic_Green_Offset		2								// Car's green light offset from the light's ID
#define DATA_Traffic_Green2_Offset		3								// Car's auxiliary green light offset from the light's ID

#define DATA_Pedestrian_Red_Offset		1								// Pedestrian's red light offset from the light's ID
#define DATA_Pedestrian_Green_Offset	2								// Pedestrian's green light offset from the light's ID
#define DATA_Pedestrian_Blink_Offset	3								// Pedestrian's blinking light offset from the light's ID

#define DATA_Train						3								// Train lights and buttons line (row)
#define LIGHT_Train_White				0								// Train light white port's location in the row
#define LIGHT_Train_Red1				2								// Train light red1 port's location in the row
#define LIGHT_Train_Red2				4								// Train light red2 port's location in the row
#define TRAIN_First_Light				LIGHT_Train_White				// Alternate name for the "LIGHT_Train_White" when using with an offset
#define TRAIN_Light_Count				3								// How many train lights are there
#define TRAIN_Pin_Offset				1								// Pin's offset from the port (They are in a row)
#define DATA_Train_Button_Left_Port		6								// Train button left port's location in the row
#define DATA_Train_Button_Right_Port	8								// Train button right port's location in the row

#define DATA_Service_Button_On			0								// Service button on's line (row)
#define DATA_Service_Button_Off			1								// Service button off's line (row)
#define DATA_Service_Button_Port		0								// Service buttons port's column
#define DATA_Service_Button_Pin			1								// Service buttons pin's column

#define TRAINMANAGER_Bit_Tick			0								// Train manager's bit where the alternating value can be found
#define TRAINMANAGER_Bit_Left			1								// Train manager's bit where the button left's saved value can be found
#define TRAINMANAGER_Bit_Right			2								// Train manager's bit where the button right's saved value can be found
#define TRAINMANAGER_Bit_Is_Train		3								// Train manager's bit where the trains state can be fond (there is or there is no train)

#define PRESSED_Train_Button_Left		1								// Train button left's ID, used to make a switch-case statement more readable
#define PRESSED_Train_Button_Right		2								// Train button right's ID, used to make a switch-case statement more readable
#define PRESSED_Train_Button_None		0								// No train button pressed ID, used to make a switch-case statement more readable

#define PRESSED_Service_Button_On		1								// Service mode button on's ID, used to make a switch-case statement more readable
#define PRESSED_Service_Button_Off		2								// Service mode button off's ID, used to make a switch-case statement more readable
#define PRESSED_Service_Button_None		0								// No service mode button pressed ID, used to make a switch-case statement more readable

#define STATE_OFF						0								// The off state's ID
#define STATE_ON						1								// The on state's ID
#define STATE_BLINK						2								// The blink state's ID

#define	TYPE_CarLight					1								// The car light type's ID
#define TYPE_PedestrianLight			2								// The pedestrian light type's ID

#define HOLD_Train_Button				0								// The button manager's bit where it's saved if the train button is held down
#define HOLD_Service_Button				1								// The button manager's bit where it's saved if the service mode button is held down

#define DDR_Traffic_Light				1								// Traffic light's ddr ID, used to make a switch-case statement more readable
#define DDR_Train_Light					2								// Traibn light's ddr ID, used to make a switch-case statement more readable
#define DDR_Train_Button				3								// Train button's ddr ID, used to make a switch-case statement more readable
#define DDR_Service_Button				4								// Service mode button's ddr ID, used to make a switch-case statement more readable

#define BLINK_EFFECT					51								// SW PWM blinking light's alternating time (must be 255's divisor)
#define DATA_PWM_Offset					3								// Offset in the mastertable for the light's pwm brightness
#define DATA_Direction_Offset			2								// Offseb ub the mastertable for the sw pwm fading direction

#define GPIO_PORTA						1								// Port A's ID
#define GPIO_PORTB						2								// Port B's ID
#define GPIO_PORTC						3								// Port C's ID
#define GPIO_PORTD						4								// Port D's ID
#define GPIO_PORTE						5								// Port E's ID
#define GPIO_PORTF						6								// Port F's ID
#define GPIO_PORTG						7								// Port G's ID
#define GPIO_PORTH						8								// Port H's ID


//////////////////////////////////////////////////////////////////////////
// Function declarations
//////////////////////////////////////////////////////////////////////////

// Initialization
void PortInitialization();									// Initializes all the pins from the master table
void SetDDR(uint8_t, uint8_t);								// Choses the correct setddr function
void SetDDR_TrafficLight(uint8_t);							// Sets the traffic light pins as outputs
void SetDDR_TrainLight(uint8_t);							// Sets the train light pins as outputs
void SetDDR_TrainButton(uint8_t);							// Sets the train button pins as inputs, end turns on the pull-up resistor
void SetDDR_ServiceButton(uint8_t);							// Sets the service mode button pins as inputs, end turns on the pull-up resistor
void EnableGPIOClock(uint8_t);								// Enables the clock for the given port



// Debugging
void DebugMode();											// Prints out the master iterator to the leds

// Main program controller
void MainProgramTimerHandler(void);                         // Main program timer handler



// Mode controllers
void	Start_NewProgram(uint8_t);							// Starts the program based on the input address
void	Start_ServiceMode();								// Starts the service mode (car lights blinking yellow)
void	Stop_ServiceMode();									// Stops the service mode and returns to the correct mode



// Traffic lights
void	Controller_TrafficLight();							// Controlls the car and pedestrian lights
void	Controller_TrafficCarLight();						// Sets the car light state from the master table
void	Controller_TrafficPedestrianLight();				// Sets the pedestrian light state from the master table

void	Set_TrafficLight_MasterTable(uint8_t);				// Sets the traffic light's state based on the mastertable's value
void	Set_State_Traffic(uint8_t, uint8_t);				// Sets tha traffic light's state based on the input (on, off or blinking)

uint8_t Get_Port_Traffic(uint8_t);					        // Returns the traffic light's port from the master table based on the light's ID
uint8_t Get_Pin_Traffic(uint8_t);							// Returns the traffic light's pin from the master table based on the light's ID

void	Set_TrafficBlinkCounter(uint8_t, uint8_t);			// Sets the blink delay counter based on the light's ID and our input
void	Tick_TrafficBlinkCounter(uint8_t);					// Iterates downwards the blink delay counter
uint8_t Get_TrafficBlinkCounter(uint8_t);					// Returns the blink delay counter's current value

void SwPwm();												// SW PWM's function (runs on high frequency)


// Train
void	Controller_TrainLight();							// The train light's main controller, it turns on or off the lights

void	Set_TrainFromLeft();								// Starts or stops the train mode and outher functions if a train is comming or went to the left
void	Set_TrainFromRight();								// Starts or stops the train mode and outher functions if a train is comming or went to the right

uint8_t Get_Port_Train(uint8_t);							// Returns the train lights or buttons port from the master table
uint8_t Get_Pin_Train(uint8_t);								// Returns the train lights or buttons pins from the master table
void	Set_State_Train(uint8_t, uint8_t);					// Sets the train light's state based on the input  (on, off or blinking)

void	Set_TrainManager(uint8_t);							// Sets a bit to 1 in the train manager variable based on the input
void	Clear_TrainManager(uint8_t);						// Clears a bit to 0 in the train manager variable based on the input
uint8_t Get_TrainManager(uint8_t);							// Returns a bit's state in the train manager variable based on the input
uint8_t Is_TrainManager_Gone();								// Returns true or false if there are no trains on the tracks (Both left and right switches triggered)


// Transition
void	TransitionState();									// Initializes the tranisition state (Every light will turn red)

void	Clear_AllVolatile();								// Clears the volatile line (sets every state to 0)
void	Set_Next_Volatile(uint8_t);							// Sets the next state's adress in the volatile line
void	Set_Data_Volatile(uint8_t);							// Sets the light state to on or blink based on the input lightID



// Button
void	Controller_Button();								// The buttons main controller, it starts other functions based on the button presses

uint8_t Check_ButtonTrainLeft();							// Returns the left train button's current state
uint8_t Check_ButtonTrainRight();							// Returns the right train button's current state
uint8_t IsPressed_ButtonTrain();							// Returns which button is pressed if there is any

uint8_t Check_ButtonServiceOn();							// Returns the service mode on button's current state
uint8_t Check_ButtonServiceOff();							// Returns the service mode off button's current state
uint8_t IsPressed_ButtonService();							// Returns which button is pressed if there is any

void	Set_ButtonHoldManager(uint8_t);						// Sets a bit to 1 in the button hold manager variable based on the input
void	Clear_ButtonHoldManager(uint8_t);					// Clears a bit to 0 in the button hold manager variable based on the input
uint8_t Get_ButtonHoldManager(uint8_t);						// Returns a bit's state in the button hold manager variable based on the input



// Master table
uint8_t Get_Next_MasterTable();								// Returns the next state's address from the mastertable, based on the current line (masteriterator)
uint8_t Get_Delay_MasterTable();							// Returns the delay from the mastertable, based on the current line (masteriterator)
uint8_t Get_Type_MasterTable(uint8_t);						// Returns the light's type from the mastertable based on the lightID
uint8_t Get_CurrentState_MasterTable(uint8_t);				// Returns the light's current state from the mastertable, based on the current line and the lightID
uint8_t Get_Data_MasterTable(uint8_t, uint8_t);				// Returns a data from the mastertable based on the inputs (row and coulumn)
void Set_Data_MasterTable(uint8_t, uint8_t, uint8_t);		// Sets data to the mastertable based on the inputs (row and coulumn)
uint8_t Is_End_MasterTable(uint8_t);						// Returns true if the current lightID is the end of the master table


#endif //ARM_TRAFFIC_V2_TRAFFIC_H
