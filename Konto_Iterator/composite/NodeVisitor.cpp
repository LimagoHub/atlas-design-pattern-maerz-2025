
#include "NodeVisitor.h"

#include "abstract_node.h"

namespace composite {

    auto NodeVisitor::visit_node(abstract_node& item) -> void
    {
        item.accept(*this);
    }

} // composite

