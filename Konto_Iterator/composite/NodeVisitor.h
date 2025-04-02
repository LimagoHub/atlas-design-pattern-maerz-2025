//
// Created by JoachimWagner on 15.01.2025.
//

#pragma once

namespace composite {

    class abstract_node;
    class Kontogruppe;
    class Konto;

    class NodeVisitor {
    public:
        virtual ~NodeVisitor() = default;

        virtual auto visit_node(abstract_node& item) -> void;
        virtual auto visit_kontogruppe(Kontogruppe& item) -> void {}
        virtual auto visit_konto(Konto& item) -> void {}
    };

} // composite