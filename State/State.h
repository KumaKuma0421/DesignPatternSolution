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
		//         ��Status
		// ��Action��Stopped     ��Playing     ��Forwarding  ��Reversing   ��Recording ��
		// ������������������������������������������������������������������������������
		// Stop    ��x           ��Stop        ��Stop        ��Stop        ��Stop      ��
		//         ��            ����Stopped   ����Stopped   ����Stopped   ����Stopped ��
		// ������������������������������������������������������������������������������
		// Play    ��Play        ��x           ��Play        ��Play        ��x         ��
		//         ����Playing   ��            ����Playing   ����Playing   ��          ��
		// ������������������������������������������������������������������������������
		// Forward ��Forward     ��Forward     ��Forward     ��Forward     ��x         ��
		//         ����Forwarding����Forwarding����Forwarding����Forwarding��          ��
		// ������������������������������������������������������������������������������
		// Reverse ��Reverse     ��Reverse     ��Reverse     ��Reverse     ��x         ��
		//         ����Reversing ����Reversing ����Reversing ����Reversing ��          ��
		// ������������������������������������������������������������������������������
		// Record  ��Record      ��x           ��x           ��x           ��x         ��
		//         ����Recording ��            ��            ��            ��          ��
		// ������������������������������������������������������������������������������
		//
		State* _Matrix[(int)Action::MaxSize][(int)Status::MaxSize];
		Status _CurrentStatus;
	};
}