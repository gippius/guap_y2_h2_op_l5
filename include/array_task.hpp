#pragma once

#include <cstddef>
#include <exception>
#include <string>
#include <vector>

class PositiveRangeException : public std::exception {
public:
    explicit PositiveRangeException(std::string message);
    const char* what() const noexcept override;

private:
    std::string message_;
};

class ArrayTask {
public:
    explicit ArrayTask(const std::vector<double>& data);

    std::size_t length() const;
    std::string sourceArrayAsString() const;
    std::string transformedArrayAsString() const;

    double minElement() const;
    double sumBetweenFirstAndLastPositive() const;
    void moveZerosToFront();
    double at(std::size_t index) const;

private:
    std::vector<double> data_;
    std::size_t length_;
};

