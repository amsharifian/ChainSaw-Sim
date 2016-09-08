from cli import *
from cli_impl import new_object_name
from tracker import register_tracker

class_name = "linux-process-tracker"

def ptrack_settings_ifc():
    return SIM_get_class_interface(
        SIM_get_class(class_name), "tracker_settings")

def linux_kernel_expander(string):
    return get_completions(
        string, ptrack_settings_ifc().settings_id_list())

def new_linux_process_tracker_cmd(name, kernel):

    # Choose a name.
    real_name = new_object_name(name, "tracker")
    if real_name == None:
        print "An object called '%s' already exists." % name
        SIM_command_has_problem()
        return
    else:
        name = real_name

    # Using canned parameters?
    if kernel:
        if kernel in ptrack_settings_ifc().settings_id_list():
            print ("Using parameters suitable for %s."
                   % ptrack_settings_ifc().describe_settings(kernel))
        else:
            print "There is no named set of parameters called '%s'." % kernel
            SIM_command_has_problem()
            return

    # Finally, create the tracker.
    tracker = SIM_create_object(class_name, name, [])
    if kernel:
        ptrack_settings_ifc().use_settings(tracker, kernel)
    if SIM_is_interactive():
        print "New process tracker %s created." % name
    return (name,)

new_command("new-" + class_name, new_linux_process_tracker_cmd,
            [arg(str_t, "name", "?", None),
             arg(str_t, "kernel", "?", None,
                 expander = linux_kernel_expander)],
            type = "Debugging",
            see_also = ["new-context-switcher", "<tracker>.add-processor"],
            short = "create new Linux process tracker",
            doc = """

Create a new Linux process tracker. You may choose a named set of
parameters by giving the <i>kernel</i> argument; otherwise, you must
set the parameters manually, or use the autodetect-parameters command.

The tracker's set of processors will initially be empty. You can add
the processors you want it to watch with its add-processors
command.""")

register_tracker(class_name)
