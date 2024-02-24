#pragma once

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "parser/parser_tree.h"
#include "visitor/context/context.h"
#include <memory>
class PernyataanContext: public Context {
	public:
		PernyataanContext(
			nstd::bisa_kosong<std::unique_ptr<Context>> variableContext,
			nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext
		);
		static PernyataanContext generate(const nstd::daftar<std::unique_ptr<ParserTree>>& children);
		[[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>& getVariableContext() const;
		[[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>& getEkspresiContext() const;
	private:
		nstd::bisa_kosong<std::unique_ptr<Context>> variableContext;
		nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
};
