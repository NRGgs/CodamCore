/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos <nmattos@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/08 11:33:08 by nmattos       #+#    #+#                 */
/*   Updated: 2025/05/08 11:33:10 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int val) {
	// std::cout << "Int constructor called" << std::endl;
	this->value = roundf(val * (1 << fractionalbit));
}

Fixed::Fixed(const float val) {
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(val * (1 << fractionalbit));
}

Fixed &Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const {
	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const {
	Fixed	result;

	result.setRawBits(this->value + other.value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed	result;

	result.setRawBits(this->value - other.value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed	result;

	result.setRawBits((this->value * other.value) >> fractionalbit);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed	result;

	result.setRawBits((this->value << fractionalbit) / other.value);
	return (result);
}

// Pre-Increment (++a)
Fixed &Fixed::operator++() {
	this->value += 1;
	return (*this);
}

// Post-Increment (a++)
Fixed Fixed::operator++(int) {
	Fixed	old = *this;

	this->value += 1;
	return (old);
}

// Pre-Decrement (--a)
Fixed &Fixed::operator--() {
	this->value -= 1;
	return (*this);
}

// Post-Decrement (a--)
Fixed Fixed::operator--(int) {
	Fixed	old = *this;

	this->value -= 1;
	return (old);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return ((a > b) ? a : b);
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}

// bit shift
float	Fixed::toFloat(void) const {
	return (static_cast<float>(value) / (1 << fractionalbit));
}

int		Fixed::toInt(void) const {
	return (value >> fractionalbit);
}

std::ostream &operator<<(std::ostream &out, const Fixed &num) {
	out << num.toFloat();
	return (out);
}
