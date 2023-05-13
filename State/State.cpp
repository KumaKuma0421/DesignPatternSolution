//
// State1.cpp
//

#include "State.h"
#include "stdio.h"

using namespace GoF_State;

VoiceRecorder::VoiceRecorder ()
{
	for (int i = 0; i < (int)Action::MaxSize; i++)
	{
		for (int j = 0; j < (int)Status::MaxSize; j++)
		{
			_Matrix[i][j] = nullptr;
		}
	}

	_CurrentStatus = Status::Stopped;
}

VoiceRecorder::~VoiceRecorder ()
{

}

bool VoiceRecorder::Init ()
{
	State* matrix[(int)Action::MaxSize][(int)Status::MaxSize] =
	{
		{ new Discard (), new Stop (),    new Stop (),    new Stop (),    new Stop ()    },
		{ new Play (),    new Discard (), new Play (),    new Play (),    new Discard () },
		{ new Forward (), new Forward (), new Forward (), new Forward (), new Discard () },
		{ new Reverse (), new Reverse (), new Reverse (), new Reverse (), new Discard () },
		{ new Record (),  new Discard (), new Discard (), new Discard (), new Discard () },
	};

	for (int i = 0; i < (int)Status::MaxSize; i++)
	{
		for (int j = 0; j < (int)Action::MaxSize; j++)
		{
			_Matrix[i][j] = matrix[i][j];
		}
	}

	return true;
}

Status VoiceRecorder::Command (Action action)
{
	State* state = _Matrix[(int)action][(int)_CurrentStatus];
	Status status = state->Action ();
	if ((int)status > 0) _CurrentStatus = status;

	return status;
}

// ----------------------------------------------------------------------------

State::State ()
{

}

State::~State ()
{

}

Status Play::Action ()
{
	printf ("Now Playing.\n");
	return Status::Playing;
}

Status Stop::Action ()
{
	printf ("Now Stopped.\n");
	return Status::Stopped;
}

Status Forward::Action ()
{
	printf ("Now Forwarding\n");
	return Status::Forwarding;
}

Status Reverse::Action ()
{
	printf ("Now Reversing\n");
	return Status::Reversing;
}

Status Record::Action ()
{
	printf ("Now Recording\n");
	return Status::Recording;
}

Status Discard::Action ()
{
	printf ("Discard action\n");
	return (Status)-1;
}