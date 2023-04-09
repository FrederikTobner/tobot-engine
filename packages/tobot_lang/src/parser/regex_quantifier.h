#pragma once

namespace Tobot::Language {

    typedef enum {
        NO_QUANTIFIER, // No quantifier - exactly one
        ZERO_OR_MORE,  // *
        ONE_OR_MORE,   // +
        ZERO_OR_ONE,   // ?
        EXACTLY,       // {n}
        AT_LEAST,      // {n, }
        BETWEEN        // {n, m}
    } RegexQuantifier;

} // namespace Tobot::Language