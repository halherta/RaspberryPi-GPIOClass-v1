#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "GPIOClass.h"
using namespace std;


void sig_handler(int sig);

bool ctrl_c_pressed = false;

int main (void)
{

	struct sigaction sig_struct;
	sig_struct.sa_handler = sig_handler;
	sig_struct.sa_flags = 0;
	sigemptyset(&sig_struct.sa_mask);

	if (sigaction(SIGINT, &sig_struct, NULL) == -1) {
		cout << "Problem with sigaction" << endl;
		exit(1);
	}

	string inputstate;
	GPIOClass* gpio4 = new GPIOClass("4");
	GPIOClass* gpio17 = new GPIOClass("17");

	gpio4->export_gpio();
	gpio17->export_gpio();

	cout << " GPIO pins exported" << endl;

	gpio17->setdir_gpio("in");
	gpio4->setdir_gpio("out");

	cout << " Set GPIO pin directions" << endl;


	while(1)
	{
		usleep(500000);
		gpio17->getval_gpio(inputstate);
		cout << "Current input pin state is " << inputstate  <<endl;
		if(inputstate == "0")
		{
			cout << "input pin state is \"Pressed \".\n Will check input pin state again in 20ms "<<endl;
			usleep(20000);
            cout << "Checking again ....." << endl;
            gpio17->getval_gpio(inputstate);
		    if(inputstate == "0")
		    {
		    	cout << "input pin state is definitely \"Pressed\". Turning LED ON" <<endl;
		    	gpio4->setval_gpio("1");

		    	cout << " Waiting until pin is unpressed....." << endl;
		    	while (inputstate == "0"){
		    		gpio17->getval_gpio(inputstate);
		    	};
		    	cout << "pin is unpressed" << endl;

		    }
		    else
		    	cout << "input pin state is definitely \"UnPressed\". That was just noise." <<endl;

		}
		gpio4->setval_gpio("0");

		 if(ctrl_c_pressed)
				    {
				    	cout << "Ctrl^C Pressed" << endl;
				    	cout << "unexporting pins" << endl;
				    	gpio4->unexport_gpio();
				    	gpio17->unexport_gpio();
				    	cout << "deallocating GPIO Objects" << endl;
				    	delete gpio4;
				    	gpio4 = 0;
				    	delete gpio17;
				    	gpio17 =0;
				    	break;

				    }

	}
	cout << "Exiting....." << endl;
	return 0;
}

void sig_handler(int sig)
{
	write(0,"\nCtrl^C pressed in sig handler\n",32);
	ctrl_c_pressed = true;
}

