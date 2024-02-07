using ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation
{
    public interface IAbstractFile
    {
        ulong GetSizeInBytes();
        void accept(AbstractFileSystemVisitor visitor);
    }
}
