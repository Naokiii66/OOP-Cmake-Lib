add_library(atm_lib STATIC
    src/BankCard.cpp
    src/DebitCard.cpp
    src/CreditCard.cpp
    src/Terminal.cpp
    src/ATM.cpp
)

target_include_directories(atm_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
