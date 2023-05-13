//
// State1.h
//

#pragma once

namespace GoF_State
{
	enum class Status
	{
		Stopped,
		Playing,
		Forwarding,
		Reversing,
		Recording,
		MaxSize
	};

	enum class Action
	{
		Stop,
		Play,
		Forward,
		Reverse,
		Record,
		MaxSize
	};

	class State
	{
	public:
		State ();
		virtual ~State ();

		virtual Status Action () = 0;
	};

	class Play : public State
	{
	public:
		Status Action ();
	};

	class Stop : public State
	{
	public:
		Status Action ();
	};

	class Forward : public State
	{
	public:
		Status Action ();
	};

	class Reverse : public State
	{
	public:
		Status Action ();
	};

	class Record : public State
	{
	public:
		Status Action ();
	};

	class Discard : public State
	{
	public:
		Status Action ();
	};

	class VoiceRecorder final
	{
	public:
		VoiceRecorder ();
		~VoiceRecorder ();

		bool Init ();
		Status Command (Action action);

	private:
		//         ¨Status
		// «Action„ Stopped     „ Playing     „ Forwarding  „ Reversing   „ Recording „ 
		// „Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„§
		// Stop    „ x           „ Stop        „ Stop        „ Stop        „ Stop      „ 
		//         „             „ ¨Stopped   „ ¨Stopped   „ ¨Stopped   „ ¨Stopped „ 
		// „Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„§
		// Play    „ Play        „ x           „ Play        „ Play        „ x         „ 
		//         „ ¨Playing   „             „ ¨Playing   „ ¨Playing   „           „ 
		// „Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„§
		// Forward „ Forward     „ Forward     „ Forward     „ Forward     „ x         „ 
		//         „ ¨Forwarding„ ¨Forwarding„ ¨Forwarding„ ¨Forwarding„           „ 
		// „Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„§
		// Reverse „ Reverse     „ Reverse     „ Reverse     „ Reverse     „ x         „ 
		//         „ ¨Reversing „ ¨Reversing „ ¨Reversing „ ¨Reversing „           „ 
		// „Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„©„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„§
		// Record  „ Record      „ x           „ x           „ x           „ x         „ 
		//         „ ¨Recording „             „             „             „           „ 
		// „Ÿ„Ÿ„Ÿ„Ÿ„¨„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„¨„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„¨„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„¨„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„¨„Ÿ„Ÿ„Ÿ„Ÿ„Ÿ„£
		//
		State* _Matrix[(int)Action::MaxSize][(int)Status::MaxSize];
		Status _CurrentStatus;
	};
}