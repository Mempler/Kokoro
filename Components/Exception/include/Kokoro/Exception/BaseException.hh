#pragma once

#include <fmt/format.h>

#include <exception>
#include <string>
#include <string_view>

namespace Kokoro::Exception
{
    class BaseException : public std::exception
    {
    private:
        std::string m_sFormated;

    protected:
        explicit BaseException(const char* csWho, std::string_view csReason,
                               const char* csWhere, size_t sLine) noexcept
        {
            m_sFormated = fmt::format("{}: {}\n    At: {}:{}", csWho, csReason,
                                      csWhere, sLine);
        }

    public:
        const char* what() const noexcept { return m_sFormated.c_str(); }
    };
}  // namespace Kokoro::Exception
