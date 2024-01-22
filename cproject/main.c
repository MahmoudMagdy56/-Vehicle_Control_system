/* C Project By Mahmoud Magdy */

#include <stdio.h>
#include "File.h"

int main (void)
{
	char *States[] = {"OFF","ON"};
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char Traffic_Light_data;
	int Vehicle_Speed=50; // default case = 50
	int AC=0;   //default case is 0 --> OFF
	float Room_Temperature_data=35; // default case is 35
	float Engine_Temperature_data=35; // default case is 35
	int Engine_Temperature_Controller=0;// default case is 0 --> OFF
	char choice1,Engine_State;

	do{ // *start of do while loop 1*

		printf("a. Turn on the vehicle engine.\n");
		printf("b. Turn off the vehicle engine.\n");
		printf("c. Quit the system.\n");
		scanf(" %c", &choice1);

		switch (choice1)

		{  // *start of switch case choice1*

		case 'c' :    // Quit the system choice.

			printf("Quit  the system\n");
			break;

		case 'b' :              // Turn off the vehicle engine choice.

			Engine_State=0;
			printf("Turn off the vehicle engine \n");
			printf("\n");
			break;

		case 'a' :         // Turn on the vehicle engine choice.

			Engine_State=1;
			printf("\n");
			char choice2;

			do{ // **start of do while loop 2**

				printf("a. Turn off the engine.\n");
				printf("b. Set the traffic light color.\n");
				printf("c. Set the room temperature (Temperature Sensor).\n");
				printf("d. Set the engine temperature (Engine Temperature Sensor).\n");
				scanf(" %c",&choice2);

				switch (choice2)
				{ // **start of switch case option 2**


				case 'b' :// Set the traffic light color.


					int (*ptr_vehicle_speed) (char*);
					ptr_vehicle_speed=Set_Vehicle_Speed;

					printf("Please, Choose the traffic light color from: G or O or R\n");
					scanf(" %c",&Traffic_Light_data);
					Vehicle_Speed=(*ptr_vehicle_speed)(&Traffic_Light_data);
					if (Vehicle_Speed==30)
						{
							AC=1;
							Room_Temperature_data=Room_Temperature_data* ( (float)5/4 ) + 1;

							Engine_Temperature_Controller = 1;
							Engine_Temperature_data = Engine_Temperature_data* ( (float)5/4 ) + 1;
						}
					printf("Engine State: %s  \n",States[Engine_State]);
					printf("AC: %s  \n",States[AC]);
					printf("Vehicle Speed: %d km/hr\n",Vehicle_Speed);
					printf("Room Temperature: %f C\n",Room_Temperature_data);
					printf("Engine Temperature Controller State: %s \n",States[Engine_Temperature_Controller]);
					printf("Engine Temperature: %f C\n",Engine_Temperature_data);
					printf("\n");
					break;
					// Use Set_Vehicle_Speed Function to calculate the speed

				case 'c' : // Set the room temperature (Temperature Sensor).


					int (*ptr_room_temperature_data)(float*);
					ptr_room_temperature_data = Temperature_Controller;
					printf("Please, Enter the temperature of the room\n");
					scanf("%f",&Room_Temperature_data);
					AC = (*ptr_room_temperature_data)(&Room_Temperature_data);
					if (Vehicle_Speed==30)
						{
							AC=1;
							Room_Temperature_data=Room_Temperature_data* ( (float)5/4 ) + 1;

							Engine_Temperature_Controller = 1;
							Engine_Temperature_data = Engine_Temperature_data* ( (float)5/4 ) + 1;
						}
					printf("Engine State: %s  \n",States[Engine_State]);
					printf("AC: %s  \n",States[AC]);
					printf("Vehicle Speed: %d km/hr\n",Vehicle_Speed);
					printf("Room Temperature: %f C\n",Room_Temperature_data);
					printf("Engine Temperature Controller State: %s \n",States[Engine_Temperature_Controller]);
					printf("Engine Temperature: %f C\n",Engine_Temperature_data);
					printf("\n");
					break;
					// Use Temperature_Controller Function to set the room temperature and AC.


				case 'd' : // Set the engine temperature (Engine Temperature Sensor).


					int (*ptr_engine_controller)(float*);
					ptr_engine_controller = Engine_Controller;
					printf("Please, enter the engine temperature\n");
					scanf("%f",&Engine_Temperature_data);
					Engine_Temperature_Controller = (*ptr_engine_controller)(&Engine_Temperature_data);
					if (Vehicle_Speed==30)
						{
							AC=1;
							Room_Temperature_data=Room_Temperature_data* ( (float)5/4 ) + 1;

							Engine_Temperature_Controller = 1;
							Engine_Temperature_data = Engine_Temperature_data* ( (float)5/4 ) + 1;
					}
					printf("Engine State: %s  \n",States[Engine_State]);
					printf("AC: %s  \n",States[AC]);
					printf("Vehicle Speed: %d km/hr\n",Vehicle_Speed);
					printf("Room Temperature: %f C\n",Room_Temperature_data);
					printf("Engine Temperature Controller State: %s \n",States[Engine_Temperature_Controller]);
					printf("Engine Temperature: %f C\n",Engine_Temperature_data);
					printf("\n");
					break;
					// Use Engine_Controller Function to set the engine temperature and engine temperature controller.




				case 'a' : //Turn off the engine choice.

					break;

				default :

					printf("Invalid choice. Please, enter a valid choice\n");

				}// **end of switch case option 2**


			}while(choice2!='a'); // **end of do while loop 2**

			break;

		default :

			printf("Invalid choice. Please, enter a valid choice\n");
		}// *end of switch case option 1*

	}while (choice1!='c');  // *end of do while loop 1*



	return 0;
}
