using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration
{
    public abstract class AbstractFileSystemVisitor
    {
        public abstract void visitFile(File file);
        public abstract void visitDirectory(Directory directory);
    }
}
