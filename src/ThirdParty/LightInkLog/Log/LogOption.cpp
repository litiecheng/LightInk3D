
#include <algorithm>
#include "Log/LogOption.h"

namespace LightInk
{
	LogOption::LogOption() : m_name("LightInk"), m_format("%+"), m_level(~0u), m_flushLevel(0)
	{ 
		add_flush_level(LogLevel::LogMsg_Warning);
		add_flush_level(LogLevel::LogMsg_Error);
		add_flush_level(LogLevel::LogMsg_Fatal);
	}

	LogOption::LogOption(const LogOption & cp) : m_name(cp.m_name), m_format(cp.m_format), m_level(cp.m_level), m_flushLevel(cp.m_flushLevel)
	{
		m_channelOption.assign(cp.m_channelOption.begin(), cp.m_channelOption.end());
	}
	LogOption::~LogOption()
	{
		m_channelOption.clear();
	}
	LogOption & LogOption::operator = (const LogOption & right)
	{
		m_name = right.m_name;
		m_format = right.m_format;
		m_level = right.m_level;
		m_flushLevel = right.m_flushLevel;
		m_channelOption.assign(right.m_channelOption.begin(), right.m_channelOption.end());
		return *this;
	}

	void LogOption::set_name(const string & name)
	{
		m_name = name;
	}

	const string & LogOption::get_name() const
	{
		return m_name;
	}

	void LogOption::set_format(const string & format)
	{
		m_format = format;
	}

	const string & LogOption::get_format() const
	{
		return m_format;
	}

	void LogOption::add_level(LogLevel::LEVEL level)
	{
		m_level |= level;
	}
	void LogOption::remove_level(LogLevel::LEVEL level)
	{
		m_level &= (~level);
	}
	void LogOption::reset_level(uint32 level)
	{
		m_level = level;
	}
	uint32 LogOption::get_level() const
	{
		return m_level;
	}


	void LogOption::add_flush_level(LogLevel::LEVEL level)
	{
		m_flushLevel |= level;
	}
	void LogOption::remove_flush_level(LogLevel::LEVEL level)
	{
		m_flushLevel &= (~level);
	}
	void LogOption::reset_flush_level(uint32 level)
	{
		m_flushLevel = level;
	}
	uint32 LogOption::get_flush_level() const
	{
		return m_flushLevel;
	}

	void LogOption::add_channel(ChannelOptionBase * op)
	{
		m_channelOption.push_back(ChannelOptionPtr(op));
	}
	void LogOption::remove_channel(ChannelOptionBase * op)
	{
		m_channelOption.erase(std::remove(m_channelOption.begin(), m_channelOption.end(), op));
	}
	void LogOption::clear_channel()
	{
		m_channelOption.clear();
	}
	ChannelOptionBase::ChannelListPtr LogOption::get_channel_list() const
	{
		ChannelOptionBase::ChannelListPtr p(new ChannelOptionBase::ChannelList());
		vector<ChannelOptionPtr>::type::const_iterator end = m_channelOption.end();
		for (vector<ChannelOptionPtr>::type::const_iterator i = m_channelOption.begin(); i != end; ++i)
		{
			p->add_channel((*i)->get_channel());
		}
		return p;
	}

}