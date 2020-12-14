// Ruochen Wang (ruochwang@gmail.com)
#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <iostream>
#include <chrono> 

class TimerBase {
public:
    TimerBase(): m_start(std::chrono::system_clock::time_point::min()) {}

    void Clear() {
        m_start = std::chrono::system_clock::time_point::min();
    }

    bool IsStarted() const {
        return (m_start.time_since_epoch() != std::chrono::system_clock::duration(0));
    }

    void Start() {
        m_start = std::chrono::system_clock::now();
    }

    double GetMs() const {
        if (IsStarted()) {
            std::chrono::system_clock::duration diff;
            diff = std::chrono::system_clock::now() - m_start;
            return (unsigned long)(std::chrono::duration_cast<std::chrono::milliseconds>(diff).count());
        }
        return 0;
    }
private:
    std::chrono::system_clock::time_point m_start;
};

template <typename Timer> class basic_stopwatch {
public:
    explicit basic_stopwatch(char const* activity = "Stopwatch", bool start = true) : m_log(std::cout),
    m_activity(activity), m_timer(std::move(Timer())){
        if (start) Start();
    }

    explicit basic_stopwatch(std::ostream& log, char const* activity="Stopwatch", bool start = true) : m_log(log),
    m_activity(activity), m_timer(std::move(Timer())){ 
        if (start) Start();
    }

    ~basic_stopwatch() {
        Stop();
        Show();
    }

    unsigned long LapGet() const { return m_lap; };

    bool IsStarted() const { return m_timer.IsStarted(); }

    void Show(char const* event="Show") {
        m_log << m_activity << ": " << m_lap << "milliseconds" << std::endl;
    }

    void Start(char const *event_namee = "start") { m_timer.Start(); }

    void Stop(char const* event_name="stop") {
      if (!m_timer.IsStarted()) {
        m_lap = m_timer.GetMs();
        m_timer.Clear();
      }
    }

private:
    char const* m_activity;
    double m_lap;
    std::ostream& m_log;

    Timer m_timer;
};

typedef basic_stopwatch<TimerBase> Stopwatch;

#endif // STOPWATCH_H
