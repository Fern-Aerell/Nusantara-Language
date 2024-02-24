#include "visitor/context/variable/variable_context.h"
#include "parser/parser_tree.h"

VariableContext::VariableContext(
	Token tipe,
	Token nama,
	nstd::bisa_kosong<Token> samaDengan,
	nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext
):
	tipe(std::move(tipe)),
	nama(std::move(nama)),
	samaDengan(std::move(samaDengan)),
	ekspresiContext(std::move(ekspresiContext))
{}

VariableContext VariableContext::generate(const nstd::daftar<std::unique_ptr<ParserTree>>& children) {
	auto* tipePtr = dynamic_cast<ParserTokenTree*>(children[0].get());
	auto* namaPtr = dynamic_cast<ParserTokenTree*>(children[1].get());
	Token tipe = tipePtr->getToken();
	Token nama = namaPtr->getToken();
	nstd::bisa_kosong<Token> samaDengan;
	nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
	return VariableContext(
			std::move(tipe),
			std::move(nama),
			std::move(samaDengan),
			std::move(ekspresiContext)
	);
}

const Token& VariableContext::getTipe() {
	return this->tipe;
}

const Token& VariableContext::getNama() {
	return this->nama;
}

const nstd::bisa_kosong<Token>& VariableContext::getSamaDengan() {
	return this->samaDengan;
}

const nstd::bisa_kosong<std::unique_ptr<Context>>& VariableContext::getEkspresiContext() {
	return this->ekspresiContext;
}
