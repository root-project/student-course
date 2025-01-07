import numpy
import os
import ROOT


class DatasetMissingBranches:
    """A helper class to create a dataset with missing branches in some of the files."""

    filenames = [
        "missing_branches_1.root",
        "missing_branches_2.root",
        "missing_branches_3.root"
    ]
    treenames = ["tree_1", "tree_2", "tree_3"]
    nentries = 5

    @classmethod
    def create_dataset(cls):
        """
        Create the dataset files. The first file contains columns 'x' and 'y',
        the second contains only column 'y', the third contains only column 'x'.
        """

        with ROOT.TFile(cls.filenames[0], "RECREATE") as f:
            t = ROOT.TTree(cls.treenames[0], cls.treenames[0])
            x = numpy.array([0], dtype=int)
            y = numpy.array([0], dtype=int)
            t.Branch("x", x, "x/I")
            t.Branch("y", y, "y/I")

            for i in range(1, cls.nentries + 1):
                x[0] = i
                y[0] = 2 * i
                t.Fill()

            t.Write()

        with ROOT.TFile(cls.filenames[1], "RECREATE") as f:
            t = ROOT.TTree(cls.treenames[1], cls.treenames[1])
            y = numpy.array([0], dtype=int)
            t.Branch("y", y, "y/I")

            for i in range(1, cls.nentries + 1):
                y[0] = 3 * i
                t.Fill()

            t.Write()

        with ROOT.TFile(cls.filenames[2], "RECREATE") as f:
            t = ROOT.TTree(cls.treenames[2], cls.treenames[2])
            x = numpy.array([0], dtype=int)
            t.Branch("x", x, "x/I")

            for i in range(1, cls.nentries + 1):
                x[0] = 4 * i
                t.Fill()

            t.Write()

    @classmethod
    def cleanup_dataset(cls):
        """Cleanup the created files."""
        for filename in cls.filenames:
            if os.path.exists(filename):
                os.remove(filename)


class DatasetMismatchedJoin:
    """
    A helper class to create a dataset where the auxiliary files have some
    entries that do not match the join index of the main file.
    """

    main_file = "event_matching_main.root"
    aux_file_1 = "event_matching_aux_1.root"
    aux_file_2 = "event_matching_aux_2.root"
    main_tree_name = "events"
    aux_tree_name_1 = "auxdata_1"
    aux_tree_name_2 = "auxdata_2"

    @classmethod
    def create_dataset(cls):
        with ROOT.TFile(cls.main_file, "RECREATE") as f:
            main_tree = ROOT.TTree(cls.main_tree_name, cls.main_tree_name)
            idx = numpy.array([0], dtype=int)
            x = numpy.array([0], dtype=int)
            main_tree.Branch("idx", idx, "idx/I")
            main_tree.Branch("x", x, "x/I")

            idx[0] = 1
            x[0] = 1
            main_tree.Fill()
            idx[0] = 2
            x[0] = 2
            main_tree.Fill()
            idx[0] = 3
            x[0] = 3
            main_tree.Fill()

            main_tree.Write()

        # The first auxiliary file has matching indices 1 and 2, but not 3
        with ROOT.TFile(cls.aux_file_1, "RECREATE") as f:
            aux_tree_1 = ROOT.TTree(cls.aux_tree_name_1, cls.aux_tree_name_1)
            idx = numpy.array([0], dtype=int)
            y = numpy.array([0], dtype=int)
            aux_tree_1.Branch("idx", idx, "idx/I")
            aux_tree_1.Branch("y", y, "y/I")

            idx[0] = 1
            y[0] = 4
            aux_tree_1.Fill()
            idx[0] = 2
            y[0] = 5
            aux_tree_1.Fill()

            aux_tree_1.Write()

        # The second auxiliary file has matching indices 1 and 3, but not 2
        with ROOT.TFile(cls.aux_file_2, "RECREATE") as f:
            aux_tree_2 = ROOT.TTree(cls.aux_tree_name_2, cls.aux_tree_name_2)
            idx = numpy.array([0], dtype=int)
            z = numpy.array([0], dtype=int)
            aux_tree_2.Branch("idx", idx, "idx/I")
            aux_tree_2.Branch("z", z, "z/I")

            idx[0] = 1
            z[0] = 6
            aux_tree_2.Fill()
            idx[0] = 3
            z[0] = 7
            aux_tree_2.Fill()

            aux_tree_2.Write()

    @classmethod
    def cleanup_dataset(cls):
        for fname in [cls.main_file, cls.aux_file_1, cls.aux_file_2]:
            if os.path.exists(fname):
                os.remove(fname)
