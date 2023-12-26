# include <iostream>
#include <math.h>
#include <iomanip>	// used to limit the number of decimal places

#include <string>	// used for string manipulation
#include <sstream>	// used for conversion between strings and other types


// No using namespace 



// Declarations

	// Input Processing
	
		// MIDI Note Array, for storage of up to 50 values
		int midi[50];		// midi note number value storage of up to 50 notes, 
		int timeIn[50];		// time of note in milliseconds of up to 50 notes


		int inputCounter = 0;	// keeping track of which note we are storing values for

		std::string inputMessage = "Enter <time in milliseconds> followed by <MIDI note number>";


	// Output Processing
		
		double PI = 3.14159265358979323846;	// M_PI hasn't worked
												// Figure this out
		double sr = 48000;					// sample rate of 48kHz
		double sample;						// sample level being printed

		double initialPhase = 0;			// starting phase of each note
												// initialised at 0 so starting value of sample is 0
		double phase;						// phase calculated as the sample printer is running




// Finished Functions

	// Finished sample printer
	void samplePrinter()
{
	// For each MIDI note that is stored within
	for (int noteNumber = 0; noteNumber < inputCounter; noteNumber++)	// for loop tha runs through each of the notes sequentially
	{

		// MIDI note number to frequency conversion
		// Conversion of time to seconds
		double f = (pow(2.0, (midi[noteNumber] - 69.0) / 12.0)) * 440.0;	// using .0 in these two equations as we have an integer value there, to specify we want a double output
																	// Not necessary to put it by every number but I have for better code readability
		double t = timeIn[noteNumber] / 1000.0;






		// Printing out samples for a given frequency over a given time in milliseconds, at a sample rate of 48kHz
		// sample limited to 6 decimal places
		for (double z = 0; z < t; z = z + (1 / sr))
		{
			sample = sin(2 * PI * f * z + initialPhase);

			std::cout << std::fixed << std::setprecision(6) << sample << std::endl;	//std::fixed  




			phase = 2 * PI * f * z;	// keeping track of the phase and adding that onto our sample calculation




		}

		initialPhase = phase;	// making the phase we are keeping track of the initial phase of the next loop


	}
}	// Finished Sample Printer













// TEST RUNS
	void test1()
{
	double sr = 48;

	double f;
	double t;

	double sample;
	double PI = 3.14159;

	std::cout << "Value for f" << std::endl;
	std::cin >> f;
	std::cout << "Value for t" << std::endl;
	std::cin >> t;

	for (double x = 0; x < t; x = x + (1 / sr))
	{
		sample = sin(2 * PI * f * x);

		std::cout << sample << std::endl;

	}
} // Working fine

	void test2()
{

	double sr = 48;

	double inputFreq;
	double t;

	double sample;
	double PI = 3.14159;

	std::cout << "Value for f" << std::endl;
	std::cin >> inputFreq;
	std::cout << "Value for t" << std::endl;
	std::cin >> t;

	double f = inputFreq / 1000;

	for (double x = 0; x < t; x = x + (1 / sr))
	{
		sample = sin(2 * PI * f * x);

		std::cout << sample << std::endl;

	}
}	// Working fine

	void test3()
{


	double sr = 48;	// sample rate of 48kHz
	// in kHz because we are doing things in milliseconds

	double midi;	// midi note number value
	double t;		// time of note in milliseconds

	double sample;	// value of the sample (amplitude of wave where the sample is 
	double PI = 3.14159;


	// Input from user	---- does this come from commandline or an actual MIDI device
	std::cout << "MIDI Note Number" << std::endl;
	std::cin >> midi;
	std::cout << "Time in milliseconds" << std::endl;
	std::cin >> t;


	// MIDI note number to frequency conversion
	double f = (pow(2, (midi - 69) / 12)) * 440 / 1000;


	// Printing out samples for a given frequency over a given time in milliseconds, at a sample rate of 48kHz
	for (double x = 0; x < t; x = x + (1 / sr))
	{
		sample = sin(2 * PI * f * x);

		std::cout << sample << std::endl;

	}
}

	void test4()
{


	double sr = 48000;	// sample rate of 48kHz

	double midi;		// midi note number value
	double timeIn;		// time of note in milliseconds

	double sample;	// value of the sample (amplitude of wave where the sample is 
	double PI = 3.14159;


	// Input from user	---- does this come from commandline or an actual MIDI device
	std::cout << "MIDI Note Number" << std::endl;
	std::cin >> midi;
	std::cout << "Time in milliseconds" << std::endl;
	std::cin >> timeIn;


	// MIDI note number to frequency conversion
	// Conversion of time to seconds
	double f = (pow(2, (midi - 69) / 12)) * 440;
	double t = timeIn / 1000;

	// Printing out samples for a given frequency over a given time in milliseconds, at a sample rate of 48kHz
	for (double x = 0; x < t; x = x + (1 / sr))
	{
		sample = sin(2 * PI * f * x);

		std::cout << sample << std::endl;

	}
}

	// printing samples for 1 time and midi input - WORKS
	void test5()
{

	std::string userInput;




	double sr = 48000;	// sample rate of 48kHz

	double midi;		// midi note number value
	double timeIn;		// time of note in milliseconds

	double sample = 0.000000;	// value of the sample (amplitude of wave where the sample is 
	double PI = 3.14159;


	// Input from user
	std::cout << "Enter <time in milliseconds> followed by <MIDI note number>" << std::endl;
	std::cin >> timeIn >> midi;

	// MIDI note number to frequency conversion
	// Conversion of time to seconds
	double f = (pow(2, (midi - 69) / 12)) * 440;
	double t = timeIn / 1000;

	// Printing out samples for a given frequency over a given time in milliseconds, at a sample rate of 48kHz
	// sample limited to 6 decimal places
	for (double x = 0; x < t; x = x + (1 / sr))
	{
		sample = sin(2 * PI * f * x);


		std::cout << std::fixed << std::setprecision(6) << sample << std::endl;

	}
}

	// limiting the input to recognisable inputs - ATTEMPT
	void test6()
{





	double sr = 48000;	// sample rate of 48kHz

	double midi;		// midi note number value
	double timeIn;		// time of note in milliseconds

	double sample;
	double PI = 3.14159;





start:

	// Input from user
	std::cout << "Enter <time in milliseconds> followed by <MIDI note number>" << std::endl;

	std::cin >> timeIn >> midi;


	if (midi < 128 && midi > 0 && timeIn)






	if (midi < 0)
	{



		// MIDI note number to frequency conversion
		// Conversion of time to seconds
		double f = (pow(2, (midi - 69) / 12)) * 440;
		double t = timeIn / 1000;

		// Printing out samples for a given frequency over a given time in milliseconds, at a sample rate of 48kHz
		// sample limited to 6 decimal places
		for (double x = 0; x < t; x = x + (1 / sr))
		{
			sample = sin(2 * PI * f * x);


			std::cout << std::fixed << std::setprecision(6) << sample << std::endl;

		}
	}

	else if (midi > 0 && midi < 127)
		goto start;

	else
	{
		std::cout << "User input is not in a recognised format" << std::endl;
		goto start;
	}


}

	// printing samples for 2 time and midi inputs (Using arrays to store multiple note values) - WORKS
	void test7()
{

	double sr = 48000;	// sample rate of 48kHz

	double midi[50];		// midi note number value
	double timeIn[50];		// time of note in milliseconds

	double sample;
	double PI = 3.14159;

	int counter = 0;


	for (int x = 0; x < 50; x++)
	{

		// Input from user
		std::cout << "Enter <time in milliseconds> followed by <MIDI note number>" << std::endl;

		std::cin >> timeIn[x] >> midi[x];


		std::cout << "time = " << timeIn[x] << std::endl;
		std::cout << "midi = " << midi[x] << std::endl;
		std::cout << "counter = " << counter << std::endl;

		if (midi[x] < 0)
		{

			// For each MIDI note that is stored within
			for (int y = 0; y < counter; y++)
			{

				// MIDI note number to frequency conversion
				// Conversion of time to seconds
				double f = (pow(2, (midi[y] - 69) / 12)) * 440;
				double t = timeIn[y] / 1000;


				// Printing out samples for a given frequency over a given time in milliseconds, at a sample rate of 48kHz
				// sample limited to 6 decimal places
				for (double z = 0; z < t; z = z + (1 / sr))
				{
					sample = sin(2 * PI * f * z);

					std::cout << std::fixed << std::setprecision(6) << sample << std::endl;



				}




			}

		}

		counter = counter + 1;


	}

}

	// phase continuity between two sample - WORKS
	void test8()
{

	double sr = 48000;	// sample rate of 48kHz

	double midi[50];		// midi note number value
	double timeIn[50];		// time of note in milliseconds

	double sample;
	double PI = 3.14159;

	int counter = 0;

	double phase = 0;
	double initialPhase = 0;


	for (int x = 0; x < 50; x++)
	{

		// Input from user
		std::cout << "Enter <time in milliseconds> followed by <MIDI note number>" << std::endl;

		std::cin >> timeIn[x] >> midi[x];


		std::cout << "time = " << timeIn[x] << std::endl;
		std::cout << "midi = " << midi[x] << std::endl;
		std::cout << "counter = " << counter << std::endl;

		if (midi[x] < 0)
		{

			// For each MIDI note that is stored within
			for (int y = 0; y < counter; y++)
			{

				// MIDI note number to frequency conversion
				// Conversion of time to seconds
				double f = (pow(2, (midi[y] - 69) / 12)) * 440;
				double t = timeIn[y] / 1000;






				// Printing out samples for a given frequency over a given time in milliseconds, at a sample rate of 48kHz
				// sample limited to 6 decimal places
				for (double z = 0; z < t; z = z + (1 / sr))
				{
					sample = sin(2 * PI * f * z + initialPhase);

					std::cout << std::fixed << std::setprecision(6) << sample << std::endl;




					phase += 2 * PI * f / sr;	// keeping track of the phase and adding that onto our sample calculation
					// We are doing this in increments of 1/sr to keep in sync with our sample calculations



				}

				initialPhase = phase;	// making the phase we are keeping track of the initial phase of the next loop


			}

		}

		counter++;


	}

}

	int test10()
	{


		for (inputCounter = 0; inputCounter < 50; inputCounter++)
		{

			std::cout << "Input counter: " << inputCounter << std::endl;

			std::cout << inputMessage << std::endl;

			std::cin >> timeIn[inputCounter] >> midi[inputCounter];

			// preventing fail on string input
			if (std::cin.fail())	// if cin enters failstate because the type of input doesn't match
			{
				std::cout << "errorMessage" << std::endl;	// prints error message
				std::cin.clear();						// clears failstate
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	//ignores everything in the cin input buffer
				// for the maximum number of characters you can get in an input stream,
				// and continues until a newline is reached


				break;
			}




			if (midi[inputCounter] < 0)
				samplePrinter();


		}

		return 0;

	}

	// Preventing string and float inputs
	void test11()
	{
		for (inputCounter = 0; inputCounter < 50; inputCounter++)
		{

			std::cout << inputMessage << std::endl;



			std::cin >> timeIn[inputCounter] >> midi[inputCounter];

			// preventing fail on string input
			if (std::cin.fail())	// if cin enters failstate because the type of input doesn't match
			{
				std::cout << "User input is not in a recognised format" << std::endl;	// prints error message

				break;
			}








			// When the MIDI input is a negative number, the program will run the sample value printer
			if (midi[inputCounter] < 0)
				samplePrinter();


		}
	}

	// Preventing less than two inputs
	void test12()
	{
		for (inputCounter = 0; inputCounter < 50; inputCounter++)
		{


			std::cout << inputMessage << std::endl;


			std::string rawStringInput;
			std::getline(std::cin, rawStringInput);

			std::istringstream stringToIntegerConverter(rawStringInput);


			if (stringToIntegerConverter >> timeIn[inputCounter] >> midi[inputCounter])
			{
				std::cout << timeIn[inputCounter] << midi[inputCounter] << std::endl;

				// When the MIDI input is a negative number, the program will run the sample value printer
				if (midi[inputCounter] < 0)
					samplePrinter();

				continue;
			}

			else
			{
				std::cout << "User input is not in a recognised format" << std::endl;	// prints error message
				break;
			}


		}
	}

	// 50th line prints all samples
	// FINAL WORKING PROTOTYPE
	void test13()
	{
		for (inputCounter = 0; inputCounter < 50; inputCounter++)	// for loop that 
		{


			std::cout << inputMessage << std::endl;


			std::string rawStringInput;
			std::getline(std::cin, rawStringInput);

			std::istringstream stringToIntegerConverter(rawStringInput);



			std::string extraInputBlocker;
			if (stringToIntegerConverter >> timeIn[inputCounter] >> midi[inputCounter] && !(stringToIntegerConverter >> extraInputBlocker))
			{



				if (midi[inputCounter] > 127)
				{
					std::cout << "The MIDI 'note on' message contains data out of bounds" << std::endl;
					break;
				}

				if (timeIn[inputCounter] < timeIn[inputCounter - 1] || timeIn[inputCounter] <= 0)
				{
					std::cout << "The time values need to be non - negative and increasing in value." << std::endl;
					break;
				}


				if (inputCounter == 49 && midi[inputCounter] >= 0)
					samplePrinter();


				if (midi[inputCounter] < 0)
					samplePrinter();

				continue;

			}

			else
			{
				std::cout << "User input is not in a recognised format" << std::endl;	// prints error message
				break;
			}


		}
	}



	





	
	


int main()
{
	
	
	test13();

	return 0;
		
	
	

	


	

	
}
