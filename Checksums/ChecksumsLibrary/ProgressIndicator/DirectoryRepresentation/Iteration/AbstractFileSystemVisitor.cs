using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration
{
    public abstract class AbstractFileSystemVisitor
    {
        public abstract void visitFile(File file);

        protected Stream writer;

        protected AbstractFileSystemVisitor(Stream writer)
        {
            this.writer = writer;
        }

        public abstract void visitDirectory(Directory directory);

        protected void traverseDirectory(Directory directory)
        {
            foreach (var resource in directory.GetFilesAndDirs())
            {
                // TODO:: I know it is a bad idea, but do not see it other way!
                if (resource is File)
                {
                    visitFile((File)resource);
                }
                else
                {
                    visitDirectory((Directory)resource);
                }
            }
        }
    }
}
