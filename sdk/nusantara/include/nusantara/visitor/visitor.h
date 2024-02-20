#pragma once

#include <nusantara/parser/parser_tree.h>

#include <memory>
#include <stdexcept>

#include "nstd/daftar.h"
#include "nstd/kosong.h"
#include "nusantara/parser/parser_rule.h"

class Context {
  public:
    Context() = default;  // constructor
    virtual ~Context() =
        default;  // destructor (virtual if X is meant to be a base class)
    Context(const Context&) = default;                 // copy constructor
    Context& operator=(const Context&) = default;      // copy assignment
    Context(Context&&) noexcept = default;             // move constructor
    Context& operator=(Context&&) noexcept = default;  // move assignment

  private:
};

class OperasiKaliSamaDenganContext: public Context {
  public:
    static OperasiKaliSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiSamaDenganContext: public Context {
  public:
    static OperasiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiAtauContext: public Context {
  public:
    static OperasiAtauContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiDanContext: public Context {
  public:
    static OperasiDanContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiOrBitContext: public Context {
  public:
    static OperasiOrBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiXorBitContext: public Context {
  public:
    static OperasiXorBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiAndBitContext: public Context {
  public:
    static OperasiAndBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiTidakSamaContext: public Context {
  public:
    static OperasiTidakSamaContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiSamaContext: public Context {
  public:
    static OperasiSamaContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiLebihBesarSamaDenganContext: public Context {
  public:
    static OperasiLebihBesarSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiLebihBesarContext: public Context {
  public:
    static OperasiLebihBesarContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiLebihKecilSamaDenganContext: public Context {
  public:
    static OperasiLebihKecilSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiLebihKecilContext: public Context {
  public:
    static OperasiLebihKecilContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiGeserKananBitContext: public Context {
  public:
    static OperasiGeserKananBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiGeserKiriBitContext: public Context {
  public:
    static OperasiGeserKiriBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiKurangContext: public Context {
  public:
    static OperasiKurangContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiTambahContext: public Context {
  public:
    static OperasiTambahContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiSisaPembagianContext: public Context {
  public:
    static OperasiSisaPembagianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiPembagianContext: public Context {
  public:
    static OperasiPembagianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiPerkalianContext: public Context {
  public:
    static OperasiPerkalianContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiTidakContext: public Context {
  public:
    static OperasiTidakContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiNotBitContext: public Context {
  public:
    static OperasiNotBitContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiKurangSatuContext: public Context {
  public:
    static OperasiKurangSatuContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiBagiSamaDenganContext: public Context {
  public:
    static OperasiBagiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

class OperasiSisaBagiSamaDenganContext: public Context {
  public:
		explicit OperasiSisaBagiSamaDenganContext(
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiBagiSamaDenganContext
		):
		kumpulanOperasiBagiSamaDenganContext(std::move(kumpulanOperasiBagiSamaDenganContext))
		{}
    static OperasiSisaBagiSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiBagiSamaDenganContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::operasi_bagi_sama_dengan) {	
						kumpulanOperasiBagiSamaDenganContext.push_back(
								std::make_unique<OperasiBagiSamaDenganContext>(
									OperasiBagiSamaDenganContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return OperasiSisaBagiSamaDenganContext(
					std::move(kumpulanOperasiBagiSamaDenganContext)
			);
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanOperasiBagiSamaDenganContext() const {
			return this->kumpulanOperasiBagiSamaDenganContext;
		}
  private:
		nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiBagiSamaDenganContext;
};

class OperasiTambahSamaDenganContext: public Context {
  public:
		explicit OperasiTambahSamaDenganContext(
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSisaBagiSamaDenganContext
		):
		kumpulanOperasiSisaBagiSamaDenganContext(std::move(kumpulanOperasiSisaBagiSamaDenganContext))
		{}
    static OperasiTambahSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSisaBagiSamaDenganContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::operasi_sisa_bagi_sama_dengan) {	
						kumpulanOperasiSisaBagiSamaDenganContext.push_back(
								std::make_unique<OperasiSisaBagiSamaDenganContext>(
									OperasiSisaBagiSamaDenganContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return OperasiTambahSamaDenganContext(
					std::move(kumpulanOperasiSisaBagiSamaDenganContext)
			);
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanOperasiSisaBagiSamaDenganContext() const {
			return this->kumpulanOperasiSisaBagiSamaDenganContext;
		}
  private:
		nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiSisaBagiSamaDenganContext;
};

class OperasiKurangSamaDenganContext: public Context {
  public:
		explicit OperasiKurangSamaDenganContext(
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTambahSamaDenganContext
		):
		kumpulanOperasiTambahSamaDenganContext(std::move(kumpulanOperasiTambahSamaDenganContext))
		{}
    static OperasiKurangSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTambahSamaDenganContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::operasi_tambah_sama_dengan) {	
						kumpulanOperasiTambahSamaDenganContext.push_back(
								std::make_unique<OperasiTambahSamaDenganContext>(
									OperasiTambahSamaDenganContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return OperasiKurangSamaDenganContext(
					std::move(kumpulanOperasiTambahSamaDenganContext)
			);
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanOperasiTambahSamaDenganContext() const {
			return this->kumpulanOperasiTambahSamaDenganContext;
		}
  private:
		nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiTambahSamaDenganContext;
};

class OperasiAndBitSamaDenganContext: public Context {
  public:
		explicit OperasiAndBitSamaDenganContext(
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangSamaDenganContext
		):
		kumpulanOperasiKurangSamaDenganContext(std::move(kumpulanOperasiKurangSamaDenganContext))
		{}
    static OperasiAndBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangSamaDenganContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::operasi_kurang_sama_dengan) {	
						kumpulanOperasiKurangSamaDenganContext.push_back(
								std::make_unique<OperasiKurangSamaDenganContext>(
									OperasiKurangSamaDenganContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return OperasiAndBitSamaDenganContext(
					std::move(kumpulanOperasiKurangSamaDenganContext)
			);
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanOperasiKurangSamaDenganContext() const {
			return this->kumpulanOperasiKurangSamaDenganContext;
		}
  private:
		nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiKurangSamaDenganContext;
};

class OperasiOrBitSamaDenganContext: public Context {
  public:
		explicit OperasiOrBitSamaDenganContext(
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiAndBitSamaDenganContext
		):
		kumpulanOperasiAndBitSamaDenganContext(std::move(kumpulanOperasiAndBitSamaDenganContext))
		{}
    static OperasiOrBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiAndBitSamaDenganContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::operasi_and_bit_sama_dengan) {	
						kumpulanOperasiAndBitSamaDenganContext.push_back(
								std::make_unique<OperasiAndBitSamaDenganContext>(
									OperasiAndBitSamaDenganContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return OperasiOrBitSamaDenganContext(
					std::move(kumpulanOperasiAndBitSamaDenganContext)
			);
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanOperasiAndBitSamaDenganContext() const {
			return this->kumpulanOperasiAndBitSamaDenganContext;
		}
  private:
		nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiAndBitSamaDenganContext;
};

class OperasiXorBitSamaDenganContext: public Context {
  public:
		explicit OperasiXorBitSamaDenganContext(
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiOrBitSamaDenganContext
		):
		kumpulanOperasiOrBitSamaDenganContext(std::move(kumpulanOperasiOrBitSamaDenganContext))
		{}
    static OperasiXorBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiOrBitSamaDenganContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::operasi_or_bit_sama_dengan) {	
						kumpulanOperasiOrBitSamaDenganContext.push_back(
								std::make_unique<OperasiOrBitSamaDenganContext>(
									OperasiOrBitSamaDenganContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return OperasiXorBitSamaDenganContext(
					std::move(kumpulanOperasiOrBitSamaDenganContext)
			);
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanOperasiOrBitSamaDenganContext() const {
			return this->kumpulanOperasiOrBitSamaDenganContext;
		}
  private:
		nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiOrBitSamaDenganContext;
};

class OperasiGeserKiriBitSamaDenganContext: public Context {
  public:
		explicit OperasiGeserKiriBitSamaDenganContext(
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiXorBitSamaDenganContext
		):
		kumpulanOperasiXorBitSamaDenganContext(std::move(kumpulanOperasiXorBitSamaDenganContext))
		{}
    static OperasiGeserKiriBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiXorBitSamaDenganContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::operasi_xor_bit_sama_dengan) {	
						kumpulanOperasiXorBitSamaDenganContext.push_back(
								std::make_unique<OperasiXorBitSamaDenganContext>(
									OperasiXorBitSamaDenganContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return OperasiGeserKiriBitSamaDenganContext(
					std::move(kumpulanOperasiXorBitSamaDenganContext)
			);
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanOperasiXorBitSamaDenganContext() const {
			return this->kumpulanOperasiXorBitSamaDenganContext;
		}
  private:
		nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiXorBitSamaDenganContext;
};

class OperasiGeserKananBitSamaDenganContext: public Context {
  public:
		explicit OperasiGeserKananBitSamaDenganContext(
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiGeserKiriBitSamaDenganContext
		):
		kumpulanOperasiGeserKiriBitSamaDenganContext(std::move(kumpulanOperasiGeserKiriBitSamaDenganContext))
		{}
    static OperasiGeserKananBitSamaDenganContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
			nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiGeserKiriBitSamaDenganContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::operasi_geser_kiri_bit_sama_dengan) {	
						kumpulanOperasiGeserKiriBitSamaDenganContext.push_back(
								std::make_unique<OperasiGeserKiriBitSamaDenganContext>(
									OperasiGeserKiriBitSamaDenganContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return OperasiGeserKananBitSamaDenganContext(
					std::move(kumpulanOperasiGeserKiriBitSamaDenganContext)
			);
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanOperasiGeserKiriBitSamaDenganContext() const {
			return this->kumpulanOperasiGeserKiriBitSamaDenganContext;
		}
  private:
		nstd::daftar<std::unique_ptr<Context>> kumpulanOperasiGeserKiriBitSamaDenganContext;
};

class EkspresiContext: public Context {
  public:
		explicit EkspresiContext(
			std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext
		):
		operasiGeserKananBitSamaDenganContext(std::move(operasiGeserKananBitSamaDenganContext))
		{}
    static EkspresiContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
			std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext = std::make_unique<OperasiGeserKananBitSamaDenganContext>(OperasiGeserKananBitSamaDenganContext::generate(children[0]->getChildren()));
      return EkspresiContext(std::move(operasiGeserKananBitSamaDenganContext));
    }
		[[nodiscard]] const std::unique_ptr<Context>& getOperasiGeserKananBitSamaDenganContext() const {
			return this->operasiGeserKananBitSamaDenganContext;
		}
  private:
		std::unique_ptr<Context> operasiGeserKananBitSamaDenganContext; 
};

class NusantaraContext: public Context {
  public:
		explicit NusantaraContext(
				nstd::daftar<std::unique_ptr<Context>> kumpulanEkspresiContext
		)
		: kumpulanEkspresiContext(std::move(kumpulanEkspresiContext)) 
		{}
    static NusantaraContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
			nstd::daftar<std::unique_ptr<Context>> kumpulanEkspresiContext;
			for(const std::unique_ptr<ParserTree>& child : children) {
				if(auto* prt = dynamic_cast<ParserRuleTree*>(child.get())) {
					if(prt->getRule() == ParserRule::ekspresi) {	
						kumpulanEkspresiContext.push_back(
								std::make_unique<EkspresiContext>(
									EkspresiContext::generate(prt->getChildren())
								)
						);
					}
				}
			}
      return NusantaraContext(std::move(kumpulanEkspresiContext));
    }
		[[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>& getKumpulanEkspresi() const {
			return this->kumpulanEkspresiContext;
		}
  private:
	nstd::daftar<std::unique_ptr<Context>> kumpulanEkspresiContext;
};


class NilaiKalimatContext: public Context {
  public:
    NilaiKalimatContext(
        nstd::daftar<Token> kumpulanToken,
        nstd::daftar<std::unique_ptr<Context>>
            kumpulanEkspresiContext
    ):
        kumpulanToken(std::move(kumpulanToken)),
        kumpulanEkspresiContext(std::move(kumpulanEkspresiContext)){};

    static NilaiKalimatContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      nstd::daftar<Token> kumpulanToken;
      nstd::daftar<std::unique_ptr<Context>>
          kumpulanEkspresiContext;
      for(size_t index = 0; index < children.size(); ++index) {
				if(index != 0 && index != (children.size() - 1)) {
  	      if(auto* ptchildRule = dynamic_cast<ParserRuleTree*>(children[index].get())) {
	          kumpulanEkspresiContext.push_back(
							std::make_unique<EkspresiContext>(
      	        EkspresiContext::generate(ptchildRule->getChildren())
    	      	)
						);
	        } else if(auto* ptchildToken = dynamic_cast<ParserTokenTree*>(children[index].get())) {
          	kumpulanToken.push_back(ptchildToken->getToken());
        	}
				}
      }
      return {std::move(kumpulanToken), std::move(kumpulanEkspresiContext)};
    }

    [[nodiscard]] const nstd::daftar<Token>&
    getKumpulanToken() const {
      return this->kumpulanToken;
    }

    [[nodiscard]] const nstd::daftar<std::unique_ptr<Context>>&
    getkumpulanEkspresiContext() const {
      return this->kumpulanEkspresiContext;
    }

  private:
    nstd::daftar<Token> kumpulanToken;
    nstd::daftar<std::unique_ptr<Context>> kumpulanEkspresiContext;
};

class NilaiContext: public Context {
  public:
    NilaiContext(
        nstd::bisa_kosong<Token> nilai, 
        nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext,
        nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext
    ):
        nilai(std::move(nilai)),
        ekspresiContext(std::move(ekspresiContext)),
        nilaiKalimatContext(std::move(nilaiKalimatContext)){};

    static NilaiContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      if(auto* ptchildToken =
             dynamic_cast<ParserTokenTree*>(children[0].get())) {
        const Token token = ptchildToken->getToken();
        const TokenType type = token.getType();
        const nstd::daftar<TokenType> nilaiTokenType = {
            TokenType::BILANGAN, TokenType::BENAR, TokenType::SALAH
        };
        if(nstd::contains<TokenType>(nilaiTokenType, type)) {
          nstd::bisa_kosong<Token> nilai = token;
          return NilaiContext(std::move(nilai), {}, {});
        } else if(type == TokenType::KURUNG_BUKA) {
          nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
          auto* ptchild1 = dynamic_cast<ParserRuleTree*>(children[1].get());
          if(nstd::kosong(ekspresiContext)) {
            ekspresiContext = std::make_unique<EkspresiContext>(
                EkspresiContext::generate(ptchild1->getChildren())
            );
          }
          return NilaiContext(
              {}, 
							std::move(ekspresiContext),
							{}
          );
        }
      } else if(auto* ptchildRule = dynamic_cast<ParserRuleTree*>(children[0].get())) {
        if(ptchildRule->getRule() == ParserRule::nilai_kalimat) {
          nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext =
              std::make_unique<NilaiKalimatContext>(
                  NilaiKalimatContext::generate(ptchildRule->getChildren())
              );
          return NilaiContext({}, {}, std::move(nilaiKalimatContext));
        }
      }
      throw std::runtime_error("Nilai Context Tidak Valid");
    }

    [[nodiscard]] const nstd::bisa_kosong<Token>& getNilai() const {
      return this->nilai;
    }

    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>&
    getEkspresiContext() const {
      return this->ekspresiContext;
    }

    [[nodiscard]] const nstd::bisa_kosong<std::unique_ptr<Context>>&
    getNilaiKalimatContext() const {
      return this->nilaiKalimatContext;
    }

  private:
    nstd::bisa_kosong<Token> nilai;
    nstd::bisa_kosong<std::unique_ptr<Context>> ekspresiContext;
    nstd::bisa_kosong<std::unique_ptr<Context>> nilaiKalimatContext;
};

class OperasiTambahSatuContext: public Context {
  public:
    static OperasiTambahSatuContext generate(
        const nstd::daftar<std::unique_ptr<ParserTree>>& children
    ) {
      return {};
    }

  private:
};

template<typename T>
class Visitor {
  public:
    Visitor() = default;  // constructor
    virtual ~Visitor() =
        default;  // destructor (virtual if X is meant to be a base class)
    Visitor(const Visitor&) = default;                 // copy constructor
    Visitor& operator=(const Visitor&) = default;      // copy assignment
    Visitor(Visitor&&) noexcept = default;             // move constructor
    Visitor& operator=(Visitor&&) noexcept = default;  // move assignment

    T visit(const std::unique_ptr<ParserTree>& tree) {
      if(auto* rule = dynamic_cast<ParserRuleTree*>(tree.get())) {
        switch(rule->getRule()) {
          case ParserRule::nusantara:
            return this->visitNusantara(
                NusantaraContext::generate(rule->getChildren())
            );
          case ParserRule::ekspresi:
            return this->visitEkspresi(
                EkspresiContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kanan_bit_sama_dengan:
            return this->visitOperasiGeserKananBitSamaDengan(
                OperasiGeserKananBitSamaDenganContext::generate(
                    rule->getChildren()
                )
            );
          case ParserRule::operasi_geser_kiri_bit_sama_dengan:
            return this->visitOperasiGeserKiriBitSamaDengan(
                OperasiGeserKiriBitSamaDenganContext::generate(
                    rule->getChildren()
                )
            );
          case ParserRule::operasi_xor_bit_sama_dengan:
            return this->visitOperasiXorBitSamaDengan(
                OperasiXorBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_or_bit_sama_dengan:
            return this->visitOperasiOrBitSamaDengan(
                OperasiOrBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_and_bit_sama_dengan:
            return this->visitOperasiAndBitSamaDengan(
                OperasiAndBitSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang_sama_dengan:
            return this->visitOperasiKurangSamaDengan(
                OperasiKurangSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah_sama_dengan:
            return this->visitOperasiTambahSamaDengan(
                OperasiTambahSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sisa_bagi_sama_dengan:
            return this->visitOperasiSisaBagiSamaDengan(
                OperasiSisaBagiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_bagi_sama_dengan:
            return this->visitOperasiBagiSamaDengan(
                OperasiBagiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kali_sama_dengan:
            return this->visitOperasiKaliSamaDengan(
                OperasiKaliSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sama_dengan:
            return this->visitOperasiSamaDengan(
                OperasiSamaDenganContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_atau:
            return this->visitOperasiAtau(
                OperasiAtauContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_dan:
            return this->visitOperasiDan(
                OperasiDanContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_or_bit:
            return this->visitOperasiOrBit(
                OperasiOrBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_xor_bit:
            return this->visitOperasiXorBit(
                OperasiXorBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_and_bit:
            return this->visitOperasiAndBit(
                OperasiAndBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tidak_sama:
            return this->visitOperasiTidakSama(
                OperasiTidakSamaContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sama:
            return this->visitOperasiSama(
                OperasiSamaContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_lebih_besar_sama_dengan:
            return this->visitOperasiLebihBesarSamaDengan(
                OperasiLebihBesarSamaDenganContext::generate(rule->getChildren()
                )
            );
          case ParserRule::operasi_lebih_besar:
            return this->visitOperasiLebihBesar(
                OperasiLebihBesarContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_lebih_kecil_sama_dengan:
            return this->visitOperasiLebihKecilSamaDengan(
                OperasiLebihKecilSamaDenganContext::generate(rule->getChildren()
                )
            );
          case ParserRule::operasi_lebih_kecil:
            return this->visitOperasiLebihKecil(
                OperasiLebihKecilContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kanan_bit:
            return this->visitOperasiGeserKananBit(
                OperasiGeserKananBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_geser_kiri_bit:
            return this->visitOperasiGeserKiriBit(
                OperasiGeserKiriBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang:
            return this->visitOperasiKurang(
                OperasiKurangContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah:
            return this->visitOperasiTambah(
                OperasiTambahContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_sisa_pembagian:
            return this->visitOperasiSisaPembagian(
                OperasiSisaPembagianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_pembagian:
            return this->visitOperasiPembagian(
                OperasiPembagianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_perkalian:
            return this->visitOperasiPerkalian(
                OperasiPerkalianContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tidak:
            return this->visitOperasiTidak(
                OperasiTidakContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_not_bit:
            return this->visitOperasiNotBit(
                OperasiNotBitContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_kurang_satu:
            return this->visitOperasiKurangSatu(
                OperasiKurangSatuContext::generate(rule->getChildren())
            );
          case ParserRule::operasi_tambah_satu:
            return this->visitOperasiTambahSatu(
                OperasiTambahSatuContext::generate(rule->getChildren())
            );
          case ParserRule::nilai:
            return this->visitNilai(NilaiContext::generate(rule->getChildren())
            );
          case ParserRule::nilai_kalimat:
            return this->visitNilaiKalimat(
                NilaiKalimatContext::generate(rule->getChildren())
            );
        }
      }
      throw std::runtime_error("Aturan tidak valid.");
    }

    virtual T visitNusantara(const NusantaraContext& ctx) = 0;
    virtual T visitEkspresi(const EkspresiContext& ctx) = 0;
    virtual T visitOperasiGeserKananBitSamaDengan(
        const OperasiGeserKananBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiGeserKiriBitSamaDengan(
        const OperasiGeserKiriBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiXorBitSamaDengan(
        const OperasiXorBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiOrBitSamaDengan(
        const OperasiOrBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiAndBitSamaDengan(
        const OperasiAndBitSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiKurangSamaDengan(
        const OperasiKurangSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiTambahSamaDengan(
        const OperasiTambahSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiSisaBagiSamaDengan(
        const OperasiSisaBagiSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiBagiSamaDengan(const OperasiBagiSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiKaliSamaDengan(const OperasiKaliSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiSamaDengan(const OperasiSamaDenganContext& ctx) = 0;
    virtual T visitOperasiAtau(const OperasiAtauContext& ctx) = 0;
    virtual T visitOperasiDan(const OperasiDanContext& ctx) = 0;
    virtual T visitOperasiOrBit(const OperasiOrBitContext& ctx) = 0;
    virtual T visitOperasiXorBit(const OperasiXorBitContext& ctx) = 0;
    virtual T visitOperasiAndBit(const OperasiAndBitContext& ctx) = 0;
    virtual T visitOperasiTidakSama(const OperasiTidakSamaContext& ctx) = 0;
    virtual T visitOperasiSama(const OperasiSamaContext& ctx) = 0;
    virtual T visitOperasiLebihBesarSamaDengan(
        const OperasiLebihBesarSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiLebihBesar(const OperasiLebihBesarContext& ctx) = 0;
    virtual T visitOperasiLebihKecilSamaDengan(
        const OperasiLebihKecilSamaDenganContext& ctx
    ) = 0;
    virtual T visitOperasiLebihKecil(const OperasiLebihKecilContext& ctx) = 0;
    virtual T visitOperasiGeserKananBit(const OperasiGeserKananBitContext& ctx
    ) = 0;
    virtual T visitOperasiGeserKiriBit(const OperasiGeserKiriBitContext& ctx
    ) = 0;
    virtual T visitOperasiKurang(const OperasiKurangContext& ctx) = 0;
    virtual T visitOperasiTambah(const OperasiTambahContext& ctx) = 0;
    virtual T visitOperasiSisaPembagian(const OperasiSisaPembagianContext& ctx
    ) = 0;
    virtual T visitOperasiPembagian(const OperasiPembagianContext& ctx) = 0;
    virtual T visitOperasiPerkalian(const OperasiPerkalianContext& ctx) = 0;
    virtual T visitOperasiTidak(const OperasiTidakContext& ctx) = 0;
    virtual T visitOperasiNotBit(const OperasiNotBitContext& ctx) = 0;
    virtual T visitOperasiKurangSatu(const OperasiKurangSatuContext& ctx) = 0;
    virtual T visitOperasiTambahSatu(const OperasiTambahSatuContext& ctx) = 0;
    virtual T visitNilai(const NilaiContext& ctx) = 0;
    virtual T visitNilaiKalimat(const NilaiKalimatContext& ctx) = 0;

  private:
};
