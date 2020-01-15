/*
 * client.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */

#include <sstream>
#include <string>
#include <iostream>
#include <unistd.h> //contains various constants

#include "SIMPLESOCKET.H"
#include "TASK3.H"

using namespace std;

/**
 *
 * \brief Returns the string "COORD[x,y]"
 * for x and y have positive integer values
 *
 */

string coordStr (int x, int y);

int main() {

	srand(time(NULL));
	TCPclient c;
	string host = "localhost";
	string msg;
	string response;
	int x, y, r;

	//connect to host
	c.conn( host, 2021);



	int i=0;
	bool goOn=1;

	int nmbShoots = 0;
	for (int j =0 ; j<100;j++)
	{

	c.sendData(string("NEWGAME"));
	msg = c.receive(32);
	nmbShoots = 0;




	while(1)// send and receive data
	{
		x = rand () % 10 + 1;
		y = rand () % 10 + 1;
		msg = coordStr (x,y);
		c.sendData(msg); //send coordinate


		msg = c.receive(32); //receive feedback

		if (1!=sscanf (msg.c_str(), "RES[%d]", &r))
		{
			cout << "unknown response: " << msg << endl;
		}else{
			nmbShoots++;
		}

		if (r == TASK3::GAME_OVER) break;

	}


	cout << nmbShoots << endl;
}
}






		/*for(int m=0 ; m<100;m++)// send and receive data
		{
			c.sendData(string("NEWGAME"));
			msg = c.receive(32);
			nmbShoots = 0;
			for(int i = 1; i<=10;i++)
			{
				for (int j =1; j<=10 ; j++)
				{

					x=i;
					y=j;
					msg = coordStr (x,y);
					c.sendData(msg); //send coordinate
					msg = c.receive(32); //receive feedback
					if (1!=sscanf (msg.c_str(), "RES[%d]", &r))
						{
							cout << "unknown response: " << msg << endl;
					}else{
							nmbShoots++;
					}
					if (r == TASK3::GAME_OVER) break;
				}
				if (r == TASK3::GAME_OVER) break;
			}
			cout << nmbShoots << endl;
		}*/







string coordStr ( int x, int y)
{
	std::stringstream ss;

	ss<<"COORD[" << x << "," << y << "]";

	return ss.str();
}


