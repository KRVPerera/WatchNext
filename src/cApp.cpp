//
// Created by Rukshan Perera on 2021-10-02.
//

#include "cApp.h"
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

void async_example()
{

  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  console_sink->set_level(spdlog::level::warn);
  console_sink->set_pattern("[multi_sink_example] [%^%l%$] %v");
  // default thread pool settings can be modified *before* creating the async logger:
  // spdlog::init_thread_pool(8192, 1); // queue with 8k items and 1 backing thread.
  const auto max_size = 1024 * 1024 * 5;
  const auto max_files = 3;
  auto async_file = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("logs/async_log.txt", max_size, max_files);
  async_file->set_level(spdlog::level::trace);

  std::vector<spdlog::sink_ptr> sinks {console_sink, async_file};
  auto logger = std::make_shared<spdlog::async_logger>("seedrmain-logger", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
  spdlog::register_logger(logger);
  logger->set_level(spdlog::level::debug);
  spdlog::warn("this should appear in both console and file");
  spdlog::info("this message should not appear in the console, only in the file");
}

wxIMPLEMENT_APP(cApp);

bool cApp::OnInit() {
    async_example();
//    auto logger = spdlog::get("seedrmain");
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

//    spdlog::warn("Easy padding in numbers like {:08d}", 12);
//    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
//    spdlog::info("Support for floats {:03.2f}", 1.23456);
//    spdlog::info("Positional args are {1} {0}..", "too", "supported");
//    spdlog::info("{:<30}", "left aligned");

    if ( !wxApp::OnInit() )
        return false;

    m_frame = new cMain();
    m_frame->Show();


    return true;
}