#pragma once


#include "parser/parser_tree.h"
#include "visitor/context/context.h"
#include <memory>
#include <optional>
#include <vector>

class PernyataanContext: public Context {
	public:
		PernyataanContext(
			std::optional<std::unique_ptr<Context>> variableContext,
			std::optional<std::unique_ptr<Context>> ekspresiContext
		);
		static PernyataanContext generate(const std::vector<std::unique_ptr<ParserTree>>& children);
		[[nodiscard]] const std::optional<std::unique_ptr<Context>>& getVariableContext() const;
		[[nodiscard]] const std::optional<std::unique_ptr<Context>>& getEkspresiContext() const;
	private:
		std::optional<std::unique_ptr<Context>> variableContext;
		std::optional<std::unique_ptr<Context>> ekspresiContext;
};
