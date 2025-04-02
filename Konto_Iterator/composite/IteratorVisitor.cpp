
#include "IteratorVisitor.h"
#include "abstract_node.h"

namespace composite {

    auto IteratorVisitor::visit_node(abstract_node& item) -> void {
        nodes.push_back(item.shared_from_this());
    }

} // composite