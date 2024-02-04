#pragma once

#include <memory>
#include <vector>
#include <nusantara/parser/parser_tree.h>
#include <nusantara/lexer/token.h>
#include <nusantara/visitor/context/operasi_penugasan_context.h>

class NusantaraContext {
  public:
    explicit NusantaraContext(
      std::unique_ptr<std::vector<OperasiPenugasanContext>> kumpulanOperasiPenugasan
    );
    [[nodiscard]] std::vector<OperasiPenugasanContext>* getKumpulanOperasiPenugasan() const;
    static NusantaraContext generateNusantaraContext(const std::vector<std::unique_ptr<ParserTree>>& children);
  private:
    std::unique_ptr<std::vector<OperasiPenugasanContext>> kumpulanOperasiPenugasan;
};