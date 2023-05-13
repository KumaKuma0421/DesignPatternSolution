//
// Validation.h
//

#pragma once

namespace GoF_ChainOfResponsibility
{
	template<typename T>
	class Validation
	{
	public:
		Validation ()
		{
			_next = nullptr;
			_reason = nullptr;
		};

		Validation& SetNext (Validation<T>& validation)
		{
			_next = &validation;
			return *_next;
		};

		bool Request (T value)
		{
			bool ret = Check (value);
			if (ret && _next) ret = _next->Request (value);
			return ret;
		};

		char* GetReason () { return _reason; };

	protected:
		static char* _reason;

	private:
		virtual bool Check (T value)
		{
			_reason = (char*)"問題ありません。";
			return true;
		};

		Validation<T>* _next;
	};

	template<typename T>
	char* Validation<T>::_reason;

	template<typename T>
	class PositiveValidation : public Validation<T>
	{
	private:
		bool Check (T value)
		{
			bool ret = true;

			if (value <= 0)
			{
				ret = false;
				Validation<T>::_reason = (char*)"正数ではありません。";
			}

			return ret;
		};
	};

	template<typename T>
	class MaxValidation : public Validation<T>
	{
	public:
		MaxValidation (T value) { _value = value; };

	private:
		MaxValidation () {};

		bool Check (T value)
		{
			bool ret = true;

			if (value > _value)
			{
				ret = false;
				Validation<T>::_reason = (char*)"最大値を超えました。";
			}

			return ret;
		};

		T _value;
	};

	template<typename T>
	class MinValidation : public Validation<T>
	{
	public:
		MinValidation (T value) { _value = value; };

	protected:

	private:
		MinValidation () {};

		bool Check (T value)
		{
			bool ret = true;

			if (value < _value)
			{
				ret = false;
				Validation<T>::_reason = (char*)"最小値を下回りました。";
			}

			return ret;
		};

		T _value;
	};

	template<typename T>
	class RangeValidation : public Validation<T>
	{
	public:
		RangeValidation (T valueBegin, T valueEnd)
		{
			_valueBegin = valueBegin;
			_valueEnd = valueEnd;
		};

	private:
		RangeValidation () {};

		bool Check (T value)
		{
			bool ret = true;

			if (value < _valueBegin || _valueEnd < value)
			{
				ret = false;
				Validation<T>::_reason = (char*)"範囲外の値です。";
			}

			return ret;
		};

		T _valueBegin;
		T _valueEnd;
	};
}