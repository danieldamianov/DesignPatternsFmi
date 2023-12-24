#ifndef __CIRCLE_TESTS_HPP
#define __CIRCLE_TESTS_HPP

#include "doctest.h"
#include "RichLabel.h"

TEST_CASE("RichLabel Fields")
{
	Color color = Color::Cyan;
	Font font = Font::Calibri;
	std::string text("sample");

	RichLabel richLabel(color, font, text);

	REQUIRE(richLabel.getColor() == color);
	REQUIRE(richLabel.getFont() == font);
	REQUIRE(richLabel.getText() == text);
}

#endif