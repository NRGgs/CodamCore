/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmattos- <nmattos-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 13:54:57 by nmattos-      #+#    #+#                 */
/*   Updated: 2025/05/05 10:52:40 by nmattos       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	this->value = roundf(val * (1 << fractionalbit));
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(val * (1 << fractionalbit));
}

// Copy assignment operator overload
// Copies the value of the copied object.
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
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
