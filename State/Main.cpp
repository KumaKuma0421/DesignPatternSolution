//
// Main.cpp
//

#include <stdio.h>
#include "State.h"

using namespace GoF_State;

int main (int argc, char** argv)
{
	Status status;
	VoiceRecorder recorder;
	recorder.Init ();

	// Stop -> Play
	status = recorder.Command (Action::Play);

	// Play -> Stop
	status = recorder.Command (Action::Stop);

	printf ("Done.\n");
}