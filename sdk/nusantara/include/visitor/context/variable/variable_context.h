#pragma once

#include "lexer/token.h"
#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"
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
		[[nodiscard]] const Token& getTipe() const;
		[[nodiscard]] const Token& getNama() const;
		[[nodiscard]] const nstd::bisa_kosong<Token>& getSamaDengan() const;
		[[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>& getEkspresiContext() const;
	private:
		Token tipe;
		Token nama;
		nstd::bisa_kosong<Token> samaDengan;
		nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
};
