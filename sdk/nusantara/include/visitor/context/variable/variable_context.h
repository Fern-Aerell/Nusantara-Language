#pragma once

#include "lexer/token.h"
#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"
#include <algorithm>
#include <memory>
class VariableContext: public Context {
	public:
		VariableContext(
			Token tipe,
			Token nama,
			nstd::bisa_kosong<Token> samaDengan,
			nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext
		);
		static VariableContext generate(const nstd::daftar<std::unique_ptr<ParserTree>>& children);
		[[nodiscard]] const Token& getTipe();
		[[nodiscard]] const Token& getNama();
		[[nodiscard]] const nstd::bisa_kosong<Token>& getSamaDengan();
		[[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>& getEkspresiContext();
	private:
		Token tipe;
		Token nama;
		nstd::bisa_kosong<Token> samaDengan;
		nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
};
