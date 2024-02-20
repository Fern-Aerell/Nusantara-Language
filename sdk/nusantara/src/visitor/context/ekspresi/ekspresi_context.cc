#include "visitor/context/ekspresi/ekspresi_context.h"

#include "visitor/context/operasi/operasi_geser_kanan_bit_sama_dengan_context.h"

EkspresiContext::EkspresiContext(
    std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext
):
    operasiGeserKananBitSamaDenganContext(
        std::move(operasiGeserKananBitSamaDenganContext)
    ) {}

EkspresiContext EkspresiContext::generate(
    const nstd::daftar<std::unique_ptr<ParserTree>>& children
) {
  std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext =
      std::make_unique<OperasiGeserKananBitSamaDenganContext>(
          OperasiGeserKananBitSamaDenganContext::generate(
              children[0]->getChildren()
          )
      );
  return EkspresiContext(std::move(operasiGeserKananBitSamaDenganContext));
}

const std::unique_ptr<Context>&
EkspresiContext::getOperasiGeserKananBitSamaDenganContext() const {
  return this->operasiGeserKananBitSamaDenganContext;
}
