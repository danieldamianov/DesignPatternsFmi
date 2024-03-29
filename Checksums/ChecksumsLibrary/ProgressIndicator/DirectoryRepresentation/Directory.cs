﻿using ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation
{
    public class Directory : AbstractFile
    {
        private List<IAbstractFile> resources;

        public Directory(List<IAbstractFile> resources, String path) : base(path)
        {
            this.resources = new List<IAbstractFile>();

            this.resources.ForEach(r => this.resources.Add(r));
        }

        public override void accept(AbstractFileSystemVisitor visitor)
        {
            visitor.visitDirectory(this);
        }

        public void AddResource(IAbstractFile resource)
        {
            this.resources.Add(resource);
        }

        public override ulong GetSizeInBytes()
        {
            return (ulong)this.resources.Sum(r => (decimal)r.GetSizeInBytes());
        }

        public IReadOnlyCollection<IAbstractFile> GetFilesAndDirs()
        {
            return this.resources.AsReadOnly();
        }
    }
}
