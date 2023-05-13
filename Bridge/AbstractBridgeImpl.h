//
// AbstractBridgeImpl.h
//

#pragma once

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

namespace GoF_Bridge
{
	enum class FilePos
	{
		Begin,
		Current,
		End
	};

	class FileOperationImpl
	{
	public:
		FileOperationImpl () {};
		virtual ~FileOperationImpl () {};

		virtual bool Open (char* fileName) = 0;
		virtual int Read (char* buffer, size_t size) = 0;
		virtual bool Write (char* buffer, size_t size) = 0;
		virtual bool SetPos (FilePos pos, long offset) = 0;
		virtual bool Flush () = 0;
		virtual bool Close () = 0;
	};

	class WindowsFileOperationImpl : public FileOperationImpl
	{
	public:
		WindowsFileOperationImpl () { _hFile = nullptr; };
		~WindowsFileOperationImpl () { if (_hFile) ::CloseHandle (_hFile); };

		bool Open (char* fileName);
		int Read (char* buffer, size_t size);
		bool Write (char* buffer, size_t size);
		bool SetPos (FilePos pos, long offset);
		bool Flush ();
		bool Close ();

	private:
		HANDLE _hFile;
	};

	class UnixFileOperationImpl : public FileOperationImpl
	{
	public:
		UnixFileOperationImpl () { _fp = nullptr; };
		~UnixFileOperationImpl () { if (_fp) fclose (_fp); };

		bool Open (char* fileName);
		int Read (char* buffer, size_t size);
		bool Write (char* buffer, size_t size);
		bool SetPos (FilePos pos, long offset);
		bool Flush ();
		bool Close ();

	private:
		FILE* _fp;
	};
}